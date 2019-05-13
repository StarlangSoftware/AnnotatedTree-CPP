//
// Created by olcay on 2019-05-13.
//

#include <fstream>
#include "TreeBankDrawable.h"
#include "ParseTreeDrawable.h"

TreeBankDrawable::TreeBankDrawable(vector<ParseTree*> parseTrees) {
    this->parseTrees = move(parseTrees);
}

TreeBankDrawable::TreeBankDrawable(const string& folder, const string& fileList) {
    ifstream treeBankFile, parseTreeFile;
    string line;
    treeBankFile.open(fileList, ifstream::in);
    while (treeBankFile.good()){
        treeBankFile >> line;
        string fileName = folder;
        fileName += "/" + line;
        parseTreeFile.open(fileName, ifstream::in);
        auto* parseTree = new ParseTreeDrawable(parseTreeFile);
        parseTree->setName(fileName);
        parseTree->setFileDescription(FileDescription(folder, line));
        parseTrees.push_back(parseTree);
        parseTreeFile.close();
    }
    treeBankFile.close();
}

vector<ParseTree *> TreeBankDrawable::getParseTrees() {
    return parseTrees;
}

ParseTreeDrawable *TreeBankDrawable::get(int index) {
    return (ParseTreeDrawable*) parseTrees.at(index);
}

ParseTreeDrawable* TreeBankDrawable::get(const string& fileName) {
    for (ParseTree* tree : parseTrees){
        if (((ParseTreeDrawable*) tree)->getFileDescription().getRawFileName() == fileName){
            return (ParseTreeDrawable*) tree;
        }
    }
}

void TreeBankDrawable::clearLayer(ViewLayerType layerType) {
    for (ParseTree* tree:parseTrees){
        auto* parseTree = (ParseTreeDrawable*) tree;
        parseTree->clearLayer(layerType);
        parseTree->save();
    }
}

void TreeBankDrawable::removeTree(int index) {
    parseTrees.erase(parseTrees.begin() + index);
}
