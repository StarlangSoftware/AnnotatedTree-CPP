//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "EnglishPropbankLayer.h"

EnglishPropbankLayer::EnglishPropbankLayer(const string &layerValue) {
    this->layerName = "englishPropbank";
    setLayerValue(layerValue);
}

void EnglishPropbankLayer::setLayerValue(const string &layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue, "#");
        for (const string &word : splitWords){
            items.emplace_back(Argument(word));
        }
    }
}
