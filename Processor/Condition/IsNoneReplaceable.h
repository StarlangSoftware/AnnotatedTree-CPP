//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNONEREPLACEABLE_H
#define ANNOTATEDTREE_ISNONEREPLACEABLE_H


#include "IsLeafNode.h"

class IsNoneReplaceable : public IsLeafNode{
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISNONEREPLACEABLE_H
