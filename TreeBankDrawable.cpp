//
// Created by olcay on 2019-05-13.
//

#include <fstream>
#include "TreeBankDrawable.h"
#include "ParseTreeDrawable.h"
using std::filesystem::directory_iterator;

TreeBankDrawable::TreeBankDrawable(vector<ParseTree*> parseTrees) {
    this->parseTrees = move(parseTrees);
}

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
