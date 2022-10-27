//
// Created by olcay on 2019-05-16.
//

#include <regex>
#include "IsNumber.h"

bool IsNumber::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return parentData == "CD" && regex_match(data, regex("[0-9,.]+"));
    }
    return false;
}
