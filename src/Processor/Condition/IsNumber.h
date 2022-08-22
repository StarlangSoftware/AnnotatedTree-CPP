//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNUMBER_H
#define ANNOTATEDTREE_ISNUMBER_H

#include "IsLeafNode.h"

class IsNumber : public IsLeafNode{
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISNUMBER_H
