//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_TREETOSTRINGCONVERTER_H
#define ANNOTATEDTREE_TREETOSTRINGCONVERTER_H


#include "LeafConverter/LeafToStringConverter.h"
#include "../ParseTreeDrawable.h"

class TreeToStringConverter {
private:
    LeafToStringConverter* converter;
    ParseTreeDrawable* parseTree;
    string convertToString(ParseNodeDrawable* parseNode) const;
public:
    string convert() const;
    TreeToStringConverter(ParseTreeDrawable* parseTree, LeafToStringConverter* converter);
};


#endif //ANNOTATEDTREE_TREETOSTRINGCONVERTER_H
