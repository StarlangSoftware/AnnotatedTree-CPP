//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "TargetLanguageWordLayer.h"
#include <StringUtils.h>

/**
 * Sets the surface form(s) of the word(s) possibly separated with space.
 * @param layerValue Surface form(s) of the word(s) possibly separated with space.
 */
TargetLanguageWordLayer::TargetLanguageWordLayer(const string& layerValue) {
    setLayerValue(layerValue);
}

/**
 * Sets the surface form(s) of the word(s). Value may consist of multiple surface form(s)
 * separated via space character.
 * @param layerValue New layer info
 */
void TargetLanguageWordLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = StringUtils::split(layerValue);
        items.insert(items.end(), splitWords.begin(), splitWords.end());
    }
}

int TargetLanguageWordLayer::getLayerSize(ViewLayerType viewLayer) const{
    return 0;
}

string TargetLanguageWordLayer::getLayerInfoAt(ViewLayerType viewLayer, int index) const{
    return "";
}

