//
// Created by olcay on 2019-05-16.
//

#include "IsEnglishLeafNode.h"
#include "IsNullElement.h"

/**
 * Checks if the parse node is a leaf node and contains a valid English word in its data.
 * @param parseNode Parse node to check.
 * @return True if the parse node is a leaf node and contains a valid English word in its data; false otherwise.
 */
bool IsEnglishLeafNode::satisfies(ParseNodeDrawable* parseNode){
    if (IsLeafNode::satisfies(parseNode)) {
        IsNullElement isNullElement;
        return !isNullElement.satisfies(parseNode);
    }
    return false;
}
