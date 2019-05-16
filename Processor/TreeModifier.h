//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_TREEMODIFIER_H
#define ANNOTATEDTREE_TREEMODIFIER_H


#include "../ParseTreeDrawable.h"
#include "NodeModification/NodeModifier.h"

class TreeModifier {
private:
    ParseTreeDrawable* parseTree;
    NodeModifier* nodeModifier;
    void nodeModify(ParseNodeDrawable* parseNode);
public:
    TreeModifier(ParseTreeDrawable* parseTree, NodeModifier* nodeModifier);
    void modify();
};


#endif //ANNOTATEDTREE_TREEMODIFIER_H
