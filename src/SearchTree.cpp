//
// Created by olcay on 2019-05-13.
//

#include "SearchTree.h"
#include "XmlDocument.h"
#include "ParseNodeDrawable.h"

/**
 * Constructs a set of ParseTreeSearchables from the given file name. It reads the xml file and for each xml element
 * that contains ParseTreeSearchable, it calls its constructor.
 * @param fileName File that contains the search info.
 */
SearchTree::SearchTree(const string& fileName) {
    XmlDocument xmlDocument(fileName);
    xmlDocument.parse();
    XmlElement* parseNode = xmlDocument.getFirstChild();
    while (parseNode != nullptr){
        if (parseNode->getName() == "tree"){
            XmlElement* nextNode = parseNode->getFirstChild();
            while (nextNode->getName() != "node" && nextNode->getName() != "leaf"){
                nextNode = nextNode->getNextSibling();
            }
            searchTrees.emplace_back(ParseTreeSearchable(nextNode));
        }
        parseNode = parseNode->getNextSibling();
    }

}

/**
 * Returns the ParseNodes in the given tree that satisfy all conditions given in the search trees.
 * @param tree Tree in which search operation will be done
 * @return ParseNodes in the given tree that satisfy all conditions given in the search trees.
 */
vector<ParseNode *> SearchTree::satisfy(const ParseTreeDrawable& tree) {
    vector<ParseNodeDrawable*> tmpResult;
    for (const ParseTreeSearchable& treeSearchable:searchTrees){
        tmpResult = tree.satisfy(treeSearchable);
        if (!tmpResult.empty()){
            vector<ParseNode*> result;
            for (ParseNodeDrawable* parseNodeDrawable: tmpResult){
                result.emplace_back(parseNodeDrawable);
            }
            return result;
        }
    }
    return vector<ParseNode*>();
}
