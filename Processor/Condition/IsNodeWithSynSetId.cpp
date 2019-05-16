//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithSynSetId.h"

IsNodeWithSynSetId::IsNodeWithSynSetId(string id) {
    this->id = move(id);
}

bool IsNodeWithSynSetId::satisfies(ParseNodeDrawable* parseNode) {
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
