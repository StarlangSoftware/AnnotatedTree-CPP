//
// Created by Olcay Taner YILDIZ on 12.05.2022.
//

#ifndef PARSETREE_PARALLELTREEBANK_H
#define PARSETREE_PARALLELTREEBANK_H


#include "TreeBank.h"

class ParallelTreeBank {
protected:
    TreeBank* fromTreeBank;
    TreeBank* toTreeBank;
    void removeDifferentTrees();
public:
    ParallelTreeBank();
    ~ParallelTreeBank();
    ParallelTreeBank(const string& folder1, const string& fileList1, const string& folder2, const string& fileList2);
    int size();
    ParseTree* fromTree(int index);
    ParseTree* toTree(int index);
    TreeBank* getFromTreeBank();
    TreeBank* getToTreeBank();
};


#endif //PARSETREE_PARALLELTREEBANK_H
