//
// Created by olcay on 2019-05-13.
//

#include "SearchTree.h"
#include "XmlDocument.h"
#include "ParseNodeDrawable.h"

SearchTree::SearchTree(string fileName) {
    XmlDocument xmlDocument(move(fileName));
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

vector<ParseNode *> SearchTree::satisfy(ParseTreeDrawable tree) {
    vector<ParseNodeDrawable*> tmpResult;
    for (ParseTreeSearchable treeSearchable:searchTrees){
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
