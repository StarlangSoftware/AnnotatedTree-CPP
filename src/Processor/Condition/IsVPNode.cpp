//
// Created by olcay on 2019-05-16.
//

#include "IsVPNode.h"

/**
 * Checks if the node is not a leaf node and its tag is VP.
 * @param parseNode Parse node to check.
 * @return True if the node is not a leaf node and its tag is VP, false otherwise.
 */
bool IsVPNode::satisfies(ParseNodeDrawable *parseNode) {
    return parseNode->numberOfChildren() > 0 && parseNode->getData().isVP();
}
