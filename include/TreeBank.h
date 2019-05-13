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
    explicit TreeBank(istream& inputFile);
    void stripPunctuation();
    int size();
    int wordCount(bool excludeStopWords);
    void save(const string& fileName);
    ParseTree* get(int index);
    int countWords(bool excludeStopWords);
};


#endif //PARSETREE_TREEBANK_H
