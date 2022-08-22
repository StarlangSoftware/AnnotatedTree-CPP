//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_NODEMODIFIER_H
#define ANNOTATEDTREE_NODEMODIFIER_H


#include "../../ParseNodeDrawable.h"

class NodeModifier {
public:
    virtual void modifier(ParseNodeDrawable* parseNode) = 0;
};


#endif //ANNOTATEDTREE_NODEMODIFIER_H
