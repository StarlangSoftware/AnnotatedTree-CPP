//
// Created by olcay on 2019-05-16.
//

#include "SemiContainsLayerInformation.h"
#include "../Condition/IsTurkishLeafNode.h"

SemiContainsLayerInformation::SemiContainsLayerInformation(ViewLayerType viewLayerType) {
    this->viewLayerType = viewLayerType;
}

bool SemiContainsLayerInformation::satisfies(const vector<ParseNodeDrawable *>& leafList) const{
    int notDone = 0, done = 0;
    for (ParseNodeDrawable* parseNode : leafList){
        if (parseNode->getLayerData(ViewLayerType::ENGLISH_WORD).find('*') == string::npos) {
            switch (viewLayerType){
                case ViewLayerType::TURKISH_WORD:
                    if (!parseNode->getLayerData(viewLayerType).empty()){
                        done++;
                    } else {
                        notDone++;
                    }
                    break;
                case ViewLayerType::PART_OF_SPEECH:
                case ViewLayerType::INFLECTIONAL_GROUP:
                case ViewLayerType::NER:
                case ViewLayerType::SEMANTICS:
                    if (IsTurkishLeafNode().satisfies(parseNode)){
                        if (!parseNode->getLayerData(viewLayerType).empty()){
                            done++;
                        } else {
                            notDone++;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    return done != 0 && notDone != 0;
}
