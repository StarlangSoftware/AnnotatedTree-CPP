//
// Created by olcay on 2019-05-16.
//

#include "IsNoneNode.h"

IsNoneNode::IsNoneNode(ViewLayerType secondLanguage) {
    this->secondLanguage = secondLanguage;
}

bool IsNoneNode::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(secondLanguage);
        return !data.empty() && data == "*NONE*";
    }
    return false;
}
