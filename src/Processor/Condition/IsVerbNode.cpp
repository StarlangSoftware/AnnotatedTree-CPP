//
// Created by olcay on 2019-05-16.
//

#include "IsVerbNode.h"

IsVerbNode::IsVerbNode(WordNet& wordNet) {
    this->wordNet = wordNet;
}

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
