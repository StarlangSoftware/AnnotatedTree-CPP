//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "TargetLanguageWordLayer.h"

TargetLanguageWordLayer::TargetLanguageWordLayer(const string& layerValue) {
    setLayerValue(layerValue);
}

void TargetLanguageWordLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        items.insert(items.end(), splitWords.begin(), splitWords.end());
    }
}

int TargetLanguageWordLayer::getLayerSize(ViewLayerType viewLayer) {
    return 0;
}

string TargetLanguageWordLayer::getLayerInfoAt(ViewLayerType viewLayer, int index) {
    return "";
}

