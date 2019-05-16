//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISTURKISHLEAFNODE_H
#define ANNOTATEDTREE_ISTURKISHLEAFNODE_H
#include "IsLeafNode.h"

class IsTurkishLeafNode : public IsLeafNode {
public:
    bool satisfies(ParseNodeDrawable* parseNode);
};


#endif //ANNOTATEDTREE_ISTURKISHLEAFNODE_H
