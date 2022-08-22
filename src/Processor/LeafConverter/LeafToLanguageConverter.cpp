//
// Created by olcay on 2019-05-16.
//

#include "LeafToLanguageConverter.h"

string LeafToLanguageConverter::leafConverter(ParseNodeDrawable *leafNode) {
    string layerData = leafNode->getLayerData(viewLayerType);
    string parentLayerData = ((ParseNodeDrawable*)leafNode->getParent())->getLayerData(viewLayerType);
    if (!layerData.empty()){
        if (layerData.find('*') != string::npos || (layerData == "0" && parentLayerData == "-NONE-")){
            return "";
        } else {
            return " " + layerData;
        }
    } else {
        return "";
    }
}
