//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithPredicate.h"

/**
 * Stores the synset id to check.
 * @param id Synset id to check
 */
IsNodeWithPredicate::IsNodeWithPredicate(const string& id) : IsNodeWithSynSetId(id) {

}

/**
 * Checks if at least one of the semantic ids of the parse node is equal to the given id and also the node is
 * annotated as PREDICATE with semantic role.
 * @param parseNode Parse node to check.
 * @return True if at least one of the semantic ids of the parse node is equal to the given id and also the node is
 * annotated as PREDICATE with semantic role, false otherwise.
 */
bool IsNodeWithPredicate::satisfies(ParseNodeDrawable* parseNode){
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    return IsNodeWithSynSetId::satisfies(parseNode) && layerInfo != nullptr && !layerInfo->getLayerData(ViewLayerType::PROPBANK).empty() && layerInfo->getLayerData(ViewLayerType::PROPBANK) == "PREDICATE";
}
