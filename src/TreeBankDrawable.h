//
// Created by olcay on 2019-05-13.
//

#ifndef ANNOTATEDTREE_TREEBANKDRAWABLE_H
#define ANNOTATEDTREE_TREEBANKDRAWABLE_H

#include "TreeBank.h"
#include "ParseTreeDrawable.h"

class TreeBankDrawable : public TreeBank{
public:
    explicit TreeBankDrawable(const vector<ParseTree*>& parseTrees);
    explicit TreeBankDrawable(const string& folder);
    [[nodiscard]] vector<ParseTree*> getParseTrees() const;
    [[nodiscard]] ParseTreeDrawable* get(int index) const;
    [[nodiscard]] ParseTreeDrawable* get(const string& fileName) const;
    void clearLayer(ViewLayerType layerType) const;
    void removeTree(int index);
};


#endif //ANNOTATEDTREE_TREEBANKDRAWABLE_H
