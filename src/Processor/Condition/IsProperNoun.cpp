//
// Created by olcay on 2019-05-16.
//

#include "IsProperNoun.h"

bool IsProperNoun::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string parentData = parseNode->getParent()->getData().getName();
        return (parentData == "NNP" || parentData == "NNPS");
    }
    return false;
}
