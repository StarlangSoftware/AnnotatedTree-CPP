//
// Created by olcay on 2019-05-16.
//

#include "IsNullElement.h"

/**
 * Checks if the parse node is a leaf node and its data is '*' and its parent's data is '-NONE-'.
 * @param parseNode Parse node to check.
 * @return True if the parse node is a leaf node and its data is '*' and its parent's data is '-NONE-', false
 * otherwise.
 */
bool IsNullElement::satisfies(ParseNodeDrawable* parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return data.find('*') != string::npos || (data == "0" && parentData == "-NONE-");
    }
    return false;

}
