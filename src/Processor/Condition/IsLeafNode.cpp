//
// Created by olcay on 2019-05-16.
//

#include "IsLeafNode.h"

/**
 * Checks if the parse node is a leaf node, i.e., it has no child.
 * @param parseNode Parse node to check.
 * @return True if the parse node is a leaf node, false otherwise.
 */
bool IsLeafNode::satisfies(ParseNodeDrawable* parseNode){
    return parseNode->numberOfChildren() == 0;
}
