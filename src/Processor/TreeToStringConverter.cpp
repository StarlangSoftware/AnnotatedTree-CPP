//
// Created by olcay on 2019-05-16.
//

#include "TreeToStringConverter.h"

string TreeToStringConverter::convertToString(ParseNodeDrawable *parseNode) const{
    if (parseNode->isLeaf()){
        return converter->leafConverter(parseNode);
    } else {
        string st;
        for (int i = 0; i < parseNode->numberOfChildren(); i++) {
            st += convertToString((ParseNodeDrawable*)parseNode->getChild(i));
        }
        return st;
    }
}

string TreeToStringConverter::convert() const{
    return convertToString((ParseNodeDrawable*)parseTree->getRoot());
}

TreeToStringConverter::TreeToStringConverter(ParseTreeDrawable* parseTree, LeafToStringConverter *converter) {
    this->parseTree = parseTree;
    this->converter = converter;
}
