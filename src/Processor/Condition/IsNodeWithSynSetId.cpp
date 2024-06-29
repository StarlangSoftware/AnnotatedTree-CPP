//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithSynSetId.h"

/**
 * Stores the synset id to check.
 * @param id Synset id to check
 */
IsNodeWithSynSetId::IsNodeWithSynSetId(const string& id) {
    this->id = id;
}

/**
 * Checks if at least one of the semantic ids of the parse node is equal to the given id.
 * @param parseNode Parse node to check.
 * @return True if at least one of the semantic ids of the parse node is equal to the given id, false otherwise.
 */
bool IsNodeWithSynSetId::satisfies(ParseNodeDrawable* parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        LayerInfo* layerInfo = parseNode->getLayerInfo();
        for (int i = 0; i < layerInfo->getNumberOfMeanings(); i++) {
            string synSetId = layerInfo->getSemanticAt(i);
            if (synSetId == id){
                return true;
            }
        }
    }
    return false;
}
