//
// Created by olcay on 2019-05-16.
//

#include "IsLeafNode.h"

bool IsLeafNode::satisfies(ParseNodeDrawable* parseNode) {
    return parseNode->numberOfChildren() == 0;
}
