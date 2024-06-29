//
// Created by olcay on 2019-05-16.
//

#include <regex>
#include "IsNumber.h"

/**
 * Checks if the node is a leaf node and contains numerals as the data and its parent has the tag CD.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and contains numerals as the data and its parent has the tag CD, false
 * otherwise.
 */
bool IsNumber::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return parentData == "CD" && regex_match(data, regex("[0-9,.]+"));
    }
    return false;
}
