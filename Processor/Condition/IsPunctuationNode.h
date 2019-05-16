//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISPUNCTUATIONNODE_H
#define ANNOTATEDTREE_ISPUNCTUATIONNODE_H
#include "IsLeafNode.h"

class IsPunctuationNode : public IsLeafNode{
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISPUNCTUATIONNODE_H
