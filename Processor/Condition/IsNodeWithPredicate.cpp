//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithPredicate.h"

IsNodeWithPredicate::IsNodeWithPredicate(string id) : IsNodeWithSynSetId(move(id)) {

}

bool IsNodeWithPredicate::satisfies(ParseNodeDrawable* parseNode) {
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    return IsNodeWithSynSetId::satisfies(parseNode) && layerInfo != nullptr && !layerInfo->getLayerData(ViewLayerType::PROPBANK).empty() && layerInfo->getLayerData(ViewLayerType::PROPBANK) == "PREDICATE";
}
