//
// Created by olcay on 2019-05-16.
//

#include "TreeToStringConverter.h"

/**
 * Converts recursively a parse node to a string. If it is a leaf node, calls the converter's leafConverter method,
 * otherwise concatenates the converted strings of its children.
 * @param parseNode Parse node to convert to string.
 * @return String form of the parse node and all of its descendants.
 */
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

/**
 * Calls the convertToString method with root of the tree to convert the parse tree to string.
 * @return String form of the parse tree.
 */
string TreeToStringConverter::convert() const{
    return convertToString((ParseNodeDrawable*)parseTree->getRoot());
}

/**
 * Constructor of the TreeToStringConverter class. Sets the attributes.
 * @param parseTree Parse tree to be converted.
 * @param converter Node to string converter interface.
 */
TreeToStringConverter::TreeToStringConverter(ParseTreeDrawable* parseTree, LeafToStringConverter *converter) {
    this->parseTree = parseTree;
    this->converter = converter;
}
