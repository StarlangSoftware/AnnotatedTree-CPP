//
// Created by olcay on 2019-05-16.
//

#include "IsPredicateVerbNode.h"

/**
 * Stores the wordnet for checking the pos tag of the synset.
 * @param wordNet Wordnet used for checking the pos tag of the synset.
 */
IsPredicateVerbNode::IsPredicateVerbNode(WordNet &wordNet) : IsVerbNode(wordNet) {
}

/**
 * Checks if the node is a leaf node and at least one of the semantic ids of the parse node belong to a verb synset,
 * and the semantic role of the node is PREDICATE.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and at least one of the semantic ids of the parse node belong to a verb
 *          synset and the semantic role of the node is PREDICATE, false otherwise.
 */
bool IsPredicateVerbNode::satisfies(ParseNodeDrawable *parseNode){
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    return IsVerbNode::satisfies(parseNode) && layerInfo != nullptr && layerInfo->getArgument().getArgumentType() == "PREDICATE";
}
