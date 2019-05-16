//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISPREDICATEVERBNODE_H
#define ANNOTATEDTREE_ISPREDICATEVERBNODE_H
#include "IsVerbNode.h"

class IsPredicateVerbNode : public IsVerbNode{
public:
    explicit IsPredicateVerbNode(WordNet& wordNet);
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISPREDICATEVERBNODE_H
