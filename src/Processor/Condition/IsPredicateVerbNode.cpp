//
// Created by olcay on 2019-05-16.
//

#include "IsPredicateVerbNode.h"

IsPredicateVerbNode::IsPredicateVerbNode(WordNet &wordNet) : IsVerbNode(wordNet) {
}

bool IsPredicateVerbNode::satisfies(ParseNodeDrawable *parseNode){
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    return IsVerbNode::satisfies(parseNode) && layerInfo != nullptr && layerInfo->getArgument().getArgumentType() == "PREDICATE";
}
