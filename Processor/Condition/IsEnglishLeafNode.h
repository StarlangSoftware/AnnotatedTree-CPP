//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISENGLISHLEAFNODE_H
#define ANNOTATEDTREE_ISENGLISHLEAFNODE_H


#include "IsLeafNode.h"

class IsEnglishLeafNode : public IsLeafNode{
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISENGLISHLEAFNODE_H
