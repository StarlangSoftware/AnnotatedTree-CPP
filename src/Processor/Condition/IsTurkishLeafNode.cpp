//
// Created by olcay on 2019-05-16.
//

#include "IsTurkishLeafNode.h"

/**
 * Checks if the parse node is a leaf node and contains a valid Turkish word in its data.
 * @param parseNode Parse node to check.
 * @return True if the parse node is a leaf node and contains a valid Turkish word in its data; false otherwise.
 */
bool IsTurkishLeafNode::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerInfo()->getLayerData(ViewLayerType::TURKISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return (!data.empty() && data.find('*') == string::npos && !(data == "0" && parentData == "-NONE-"));
    }
    return false;
}
