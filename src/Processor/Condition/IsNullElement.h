//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNULLELEMENT_H
#define ANNOTATEDTREE_ISNULLELEMENT_H


#include "IsLeafNode.h"

class IsNullElement : public IsLeafNode{
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISNULLELEMENT_H
