#include <utility>
#include <Dictionary/Word.h>
#include <vector>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "ShallowParseLayer.h"

ShallowParseLayer::ShallowParseLayer(string layerValue) {
    this->layerName = "shallowParse";
    setLayerValue(move(layerValue));
}

void ShallowParseLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitParse = Word::split(layerValue);
        items = splitParse;
    }
}
