//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_LEAFTOSTRINGCONVERTER_H
#define ANNOTATEDTREE_LEAFTOSTRINGCONVERTER_H


#include "../../ParseNodeDrawable.h"

class LeafToStringConverter {
public:
    virtual string leafConverter(ParseNodeDrawable* leafNode) = 0;
};


#endif //ANNOTATEDTREE_LEAFTOSTRINGCONVERTER_H
