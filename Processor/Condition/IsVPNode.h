//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISVPNODE_H
#define ANNOTATEDTREE_ISVPNODE_H


#include "NodeDrawableCondition.h"

class IsVPNode : public NodeDrawableCondition{
public:
    bool satisfies(ParseNodeDrawable* parseNode);
};


#endif //ANNOTATEDTREE_ISVPNODE_H
