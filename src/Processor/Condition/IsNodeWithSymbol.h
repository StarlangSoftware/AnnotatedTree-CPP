//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNODEWITHSYMBOL_H
#define ANNOTATEDTREE_ISNODEWITHSYMBOL_H


#include "NodeDrawableCondition.h"

class IsNodeWithSymbol : public NodeDrawableCondition{
private:
    string symbol;
public:
    explicit IsNodeWithSymbol(const string& symbol);
    bool satisfies(ParseNodeDrawable* parseNode) const;
};


#endif //ANNOTATEDTREE_ISNODEWITHSYMBOL_H
