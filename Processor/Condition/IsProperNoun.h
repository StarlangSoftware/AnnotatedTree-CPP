//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISPROPERNOUN_H
#define ANNOTATEDTREE_ISPROPERNOUN_H


#include "IsLeafNode.h"

class IsProperNoun : IsLeafNode {
public:
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISPROPERNOUN_H
