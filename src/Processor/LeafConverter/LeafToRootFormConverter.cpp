//
// Created by olcay on 2019-05-16.
//

#include "LeafToRootFormConverter.h"

string LeafToRootFormConverter::leafConverter(ParseNodeDrawable *parseNodeDrawable) const{
    LayerInfo* layerInfo = parseNodeDrawable->getLayerInfo();
    string rootWords = " ";
        for (int i = 0; i < layerInfo->getNumberOfWords(); i++) {
            string root = layerInfo->getMorphologicalParseAt(i).getWord()->getName();
            if (!root.empty()){
                rootWords.append(" ").append(root);
            }
        }
    return rootWords;
}
