//
// Created by olcay on 2019-05-13.
//

#include <fstream>
#include "TreeBankDrawable.h"
#include "ParseTreeDrawable.h"
using std::filesystem::directory_iterator;

/**
 * A simple constructor for TreeBankDrawable. Sets the parseTrees field with the given parameter.
 * @param parseTrees Parse trees in the treebank.
 */
TreeBankDrawable::TreeBankDrawable(const vector<ParseTree*>& parseTrees) {
    this->parseTrees = parseTrees;
}

/**
 * A constructor of {@link TreeBankDrawable} class which reads all {@link ParseTreeDrawable} files inside the given
 * folder. For each file inside that folder, the constructor creates a ParseTreeDrawable and puts in inside the list
 * parseTrees.
 * @param folder Folder where all parseTrees reside.
 */
TreeBankDrawable::TreeBankDrawable(const string& folder) {
    ifstream treeBankFile, parseTreeFile;
    string line;
    vector<string> files;
    for (const auto & file : directory_iterator(folder)) {
        if (!file.is_directory()) {
            files.emplace_back(file.path());
        }
    }
    sort(files.begin(), files.end());
    for (const string& file : files) {
        parseTreeFile.open(file, ifstream::in);
        auto* parseTree = new ParseTreeDrawable(parseTreeFile);
        parseTree->setName(file);
        parseTree->setFileDescription(FileDescription(folder, file.substr(file.find_last_of('/') + 1)));
        parseTrees.push_back(parseTree);
        parseTreeFile.close();
    }
    treeBankFile.close();
}

/**
 * Accessor for the parseTrees attribute
 * @return ParseTrees attribute
 */
vector<ParseTree *> TreeBankDrawable::getParseTrees() const{
    return parseTrees;
}

/**
 * Accessor for a specific tree with the given position in the array.
 * @param index Index of the parseTree.
 * @return Tree that is in the position index
 */
ParseTreeDrawable *TreeBankDrawable::get(int index) const{
    return (ParseTreeDrawable*) parseTrees.at(index);
}

/**
 * Accessor for a specific tree with the given file name.
 * @param fileName File name of the tree
 * @return Tree that has the given file name
 */
ParseTreeDrawable* TreeBankDrawable::get(const string& fileName) const{
    for (ParseTree* tree : parseTrees){
        if (((ParseTreeDrawable*) tree)->getFileDescription().getRawFileName() == fileName){
            return (ParseTreeDrawable*) tree;
        }
    }
}

/**
 * Clears the given layer for all nodes in all trees
 * @param layerType Layer name
 */
void TreeBankDrawable::clearLayer(ViewLayerType layerType) const {
    for (ParseTree* tree:parseTrees){
        auto* parseTree = (ParseTreeDrawable*) tree;
        parseTree->clearLayer(layerType);
        parseTree->save();
    }
}

/**
 * Removes a tree with the given position from the treebank.
 * @param index Position of the tree to be removed.
 */
void TreeBankDrawable::removeTree(int index) {
    parseTrees.erase(parseTrees.begin() + index);
}
