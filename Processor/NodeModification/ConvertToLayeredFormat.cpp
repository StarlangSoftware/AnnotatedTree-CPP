//
// Created by olcay on 2019-05-16.
//

#include "ConvertToLayeredFormat.h"

void ConvertToLayeredFormat::modifier(ParseNodeDrawable *parseNode) {
    if (parseNode->isLeaf()){
        string name = parseNode->getData().getName();
        parseNode->clearLayers();
        parseNode->getLayerInfo()->setLayerData(ViewLayerType::ENGLISH_WORD, name);
        parseNode->clearData();
    }
}
