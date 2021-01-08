//
// Created by Olcay Taner YILDIZ on 2019-04-23.
//

#ifndef PARSETREE_TREEBANK_H
#define PARSETREE_TREEBANK_H


#include "ParseTree.h"

class TreeBank {
protected:
    vector<ParseTree*> parseTrees;
public:
    TreeBank() = default;
    ~TreeBank();
    TreeBank(const string& folder, const string& fileList);
    void stripPunctuation();
    int size();
    int wordCount(bool excludeStopWords);
    ParseTree* get(int index);
};


#endif //PARSETREE_TREEBANK_H
