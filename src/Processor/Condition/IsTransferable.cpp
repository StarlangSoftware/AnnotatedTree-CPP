//
// Created by olcay on 2019-05-16.
//

#include "IsTransferable.h"
#include "IsNoneNode.h"
#include "IsNullElement.h"

IsTransferable::IsTransferable(ViewLayerType secondLanguage) {
    this->secondLanguage = secondLanguage;
}

/**
 * Checks if the node is a leaf node and is not a None or Null node.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and is not a None or Null node, false otherwise.
 */
bool IsTransferable::satisfies(ParseNodeDrawable* parseNode){
    if (IsLeafNode::satisfies(parseNode)) {
        if (IsNoneNode(secondLanguage).satisfies(parseNode)){
            return false;
        }
        return !IsNullElement().satisfies(parseNode);
    }
    return false;
}
