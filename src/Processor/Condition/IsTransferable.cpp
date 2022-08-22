//
// Created by olcay on 2019-05-16.
//

#include "IsTransferable.h"
#include "IsNoneNode.h"
#include "IsNullElement.h"

IsTransferable::IsTransferable(ViewLayerType secondLanguage) {
    this->secondLanguage = secondLanguage;
}

bool IsTransferable::satisfies(ParseNodeDrawable* parseNode) {
    if (IsLeafNode::satisfies(parseNode)) {
        if (IsNoneNode(secondLanguage).satisfies(parseNode)){
            return false;
        }
        return !IsNullElement().satisfies(parseNode);
    }
    return false;
}
