//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNONENODE_H
#define ANNOTATEDTREE_ISNONENODE_H


#include "IsLeafNode.h"

class IsNoneNode : public IsLeafNode{
private:
    ViewLayerType secondLanguage;
public:
    explicit IsNoneNode(ViewLayerType secondLanguage);
    bool satisfies(ParseNodeDrawable* parseNode);
};


#endif //ANNOTATEDTREE_ISNONENODE_H
