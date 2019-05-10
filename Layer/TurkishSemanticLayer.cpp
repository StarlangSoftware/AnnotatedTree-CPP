//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include <vector>
#include "Word.h"
#include "TurkishSemanticLayer.h"

TurkishSemanticLayer::TurkishSemanticLayer(string layerValue) {
    this->layerName = "semantics";
    setLayerValue(move(layerValue));
}

void TurkishSemanticLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitMeanings = Word::split(layerValue, "$");
        this->items = splitMeanings;
    }
}
