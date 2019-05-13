//
// Created by olcay on 2019-05-13.
//

#ifndef ANNOTATEDTREE_TREEBANKDRAWABLE_H
#define ANNOTATEDTREE_TREEBANKDRAWABLE_H

#include "TreeBank.h"
#include "ParseTreeDrawable.h"

class TreeBankDrawable : public TreeBank{
public:
    explicit TreeBankDrawable(vector<ParseTree*> parseTrees);
    TreeBankDrawable(const string& folder, const string& fileList);
    vector<ParseTree*> getParseTrees();
    ParseTreeDrawable* get(int index);
    ParseTreeDrawable* get(const string& fileName);
    void clearLayer(ViewLayerType layerType);
    void removeTree(int index);
};


#endif //ANNOTATEDTREE_TREEBANKDRAWABLE_H
