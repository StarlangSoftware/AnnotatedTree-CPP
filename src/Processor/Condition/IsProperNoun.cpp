//
// Created by olcay on 2019-05-16.
//

#include "IsProperNoun.h"

/**
 * Checks if the node is a leaf node and its parent has the tag NNP or NNPS.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and its parent has the tag NNP or NNPS, false otherwise.
 */
bool IsProperNoun::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string parentData = parseNode->getParent()->getData().getName();
        return (parentData == "NNP" || parentData == "NNPS");
    }
    return false;
}
