//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_LEAFTOLANGUAGECONVERTER_H
#define ANNOTATEDTREE_LEAFTOLANGUAGECONVERTER_H


#include "LeafToStringConverter.h"

class LeafToLanguageConverter : public LeafToStringConverter{
protected:
    ViewLayerType viewLayerType;
public:
    string leafConverter(ParseNodeDrawable* leafNode) override;
};


#endif //ANNOTATEDTREE_LEAFTOLANGUAGECONVERTER_H
