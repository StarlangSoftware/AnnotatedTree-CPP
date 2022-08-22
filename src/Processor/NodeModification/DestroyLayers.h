//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_DESTROYLAYERS_H
#define ANNOTATEDTREE_DESTROYLAYERS_H


#include "NodeModifier.h"

class DestroyLayers : public NodeModifier{
public:
    void modifier(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_DESTROYLAYERS_H
