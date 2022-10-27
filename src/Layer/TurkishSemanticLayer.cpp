//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include <vector>
#include "Dictionary/Word.h"
#include "TurkishSemanticLayer.h"

TurkishSemanticLayer::TurkishSemanticLayer(const string& layerValue) {
    this->layerName = "semantics";
    setLayerValue(layerValue);
}

void TurkishSemanticLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitMeanings = Word::split(layerValue, "$");
        this->items = splitMeanings;
    }
}
