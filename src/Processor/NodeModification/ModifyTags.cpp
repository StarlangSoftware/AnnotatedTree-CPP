//
// Created by olcay on 2019-05-16.
//

#include "ModifyTags.h"
#include <StringUtils.h>

void ModifyTags::modifier(ParseNodeDrawable *parseNode) {
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    if (layerInfo != nullptr){
        if (parseNode->getParent()->getData().getName() == "NNS"){
            bool isPlural = false;
            for (int i = 0; i < layerInfo->getNumberOfWords(); i++){
                if (layerInfo->getMorphologicalParseAt(i).isPlural()){
                    isPlural = true;
                    break;
                }
            }
            if (!isPlural){
                parseNode->getParent()->setData(Symbol("NN"));
            }
        }
    } else {
        parseNode->setData(parseNode->getData().trimSymbol());
        if (StringUtils::startsWith(parseNode->getData().getName(), "VB")){
            parseNode->setData(Symbol("VB"));
        }
    }
}
