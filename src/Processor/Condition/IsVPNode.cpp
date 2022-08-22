//
// Created by olcay on 2019-05-16.
//

#include "IsVPNode.h"

bool IsVPNode::satisfies(ParseNodeDrawable *parseNode) {
    return parseNode->numberOfChildren() > 0 && parseNode->getData().isVP();
}
