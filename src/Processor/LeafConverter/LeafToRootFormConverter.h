//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_LEAFTOROOTFORMCONVERTER_H
#define ANNOTATEDTREE_LEAFTOROOTFORMCONVERTER_H


#include "LeafToStringConverter.h"

class LeafToRootFormConverter : public LeafToStringConverter{
public:
    string leafConverter(ParseNodeDrawable* parseNodeDrawable) const override;
};


#endif //ANNOTATEDTREE_LEAFTOROOTFORMCONVERTER_H
