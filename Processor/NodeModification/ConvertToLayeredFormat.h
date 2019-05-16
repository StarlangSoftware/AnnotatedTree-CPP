//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_CONVERTTOLAYEREDFORMAT_H
#define ANNOTATEDTREE_CONVERTTOLAYEREDFORMAT_H


#include "NodeModifier.h"

class ConvertToLayeredFormat : public NodeModifier{
public:
    void modifier(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_CONVERTTOLAYEREDFORMAT_H
