//
// Created by olcay on 2019-05-16.
//

#include "NotContainsLayerInformation.h"
#include "../Condition/IsTurkishLeafNode.h"

NotContainsLayerInformation::NotContainsLayerInformation(ViewLayerType viewLayerType) {
    this->viewLayerType = viewLayerType;
}

bool NotContainsLayerInformation::satisfies(vector<ParseNodeDrawable *> leafList) {
    for (ParseNodeDrawable* parseNode : leafList){
        if (parseNode->getLayerData(ViewLayerType::ENGLISH_WORD).find('*') == string::npos) {
            switch (viewLayerType){
                case ViewLayerType::TURKISH_WORD:
                    if (!parseNode->getLayerData(viewLayerType).empty()){
                        return false;
                    }
                    break;
                case ViewLayerType::PART_OF_SPEECH:
                case ViewLayerType::INFLECTIONAL_GROUP:
                case ViewLayerType::NER:
                case ViewLayerType::SEMANTICS:
                    if (!parseNode->getLayerData(viewLayerType).empty() && IsTurkishLeafNode().satisfies(parseNode)){
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return true;
}