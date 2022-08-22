//
// Created by olcay on 2019-05-16.
//

#include "ContainsLayerInformation.h"
#include "../Condition/IsTurkishLeafNode.h"

ContainsLayerInformation::ContainsLayerInformation(ViewLayerType viewLayerType) {
    this->viewLayerType = viewLayerType;
}

bool ContainsLayerInformation::satisfies(vector<ParseNodeDrawable *> leafList) {
    for (ParseNodeDrawable* parseNode : leafList){
        if (parseNode->getLayerData(ViewLayerType::ENGLISH_WORD).find('*') == string::npos){
            switch (viewLayerType){
                case ViewLayerType::TURKISH_WORD:
                    if (parseNode->getLayerData(viewLayerType).empty()){
                        return false;
                    }
                    break;
                case ViewLayerType::PART_OF_SPEECH:
                case ViewLayerType::INFLECTIONAL_GROUP:
                case ViewLayerType::NER:
                case ViewLayerType::SEMANTICS:
                case ViewLayerType::PROPBANK:
                    if (parseNode->getLayerData(viewLayerType).empty() && IsTurkishLeafNode().satisfies(parseNode)){
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
