//
// Created by olcay on 2019-05-16.
//

#include "IsEnglishLeafNode.h"
#include "IsNullElement.h"

bool IsEnglishLeafNode::satisfies(ParseNodeDrawable* parseNode){
    if (IsLeafNode::satisfies(parseNode)) {
        IsNullElement isNullElement;
        return !isNullElement.satisfies(parseNode);
    }
    return false;
}
