//
// Created by olcay on 2019-05-16.
//

#include "IsVerbNode.h"

/**
 * Stores the wordnet for checking the pos tag of the synset.
 * @param wordNet Wordnet used for checking the pos tag of the synset.
 */
IsVerbNode::IsVerbNode(WordNet& wordNet) {
    this->wordNet = wordNet;
}

/**
 * Checks if the node is a leaf node and at least one of the semantic ids of the parse node belong to a verb synset.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and at least one of the semantic ids of the parse node belong to a verb
 * synset, false otherwise.
 */
bool IsVerbNode::satisfies(ParseNodeDrawable *parseNode){
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    if (IsLeafNode::satisfies(parseNode) && layerInfo != nullptr && !layerInfo->getLayerData(ViewLayerType::SEMANTICS).empty()){
        for (int i = 0; i < layerInfo->getNumberOfMeanings(); i++){
            string synSetId = layerInfo->getSemanticAt(i);
            if (wordNet.getSynSetWithId(synSetId) != nullptr && wordNet.getSynSetWithId(synSetId)->getPos() == Pos::VERB){
                return true;
            }
        }
    }
    return false;
}
