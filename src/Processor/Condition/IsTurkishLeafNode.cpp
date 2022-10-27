//
// Created by olcay on 2019-05-16.
//

#include "IsTurkishLeafNode.h"

bool IsTurkishLeafNode::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerInfo()->getLayerData(ViewLayerType::TURKISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        return (!data.empty() && data.find('*') == string::npos && !(data == "0" && parentData == "-NONE-"));
    }
    return false;
}
