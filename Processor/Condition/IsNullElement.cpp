//
// Created by olcay on 2019-05-16.
//

#include "IsNullElement.h"

bool IsNullElement::satisfies(ParseNodeDrawable* parseNode) {
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return data.find('*') != string::npos || (data == "0" && parentData == "-NONE-");
    }
    return false;

}
