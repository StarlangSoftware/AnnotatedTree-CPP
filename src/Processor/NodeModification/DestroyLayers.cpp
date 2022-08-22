//
// Created by olcay on 2019-05-16.
//

#include "DestroyLayers.h"

void DestroyLayers::modifier(ParseNodeDrawable *parseNode) {
    LayerInfo* layerInfo = parseNode->getLayerInfo();
    if (layerInfo != nullptr){
        layerInfo->englishClear();
        layerInfo->dependencyClear();
        layerInfo->metaMorphemesMovedClear();
    }
}
