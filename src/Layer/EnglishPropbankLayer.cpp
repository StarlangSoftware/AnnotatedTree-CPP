//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "EnglishPropbankLayer.h"

/**
 * Constructor for the propbank layer for English language.
 * @param layerValue Value for the English propbank layer.
 */
EnglishPropbankLayer::EnglishPropbankLayer(const string &layerValue) {
    this->layerName = "englishPropbank";
    setLayerValue(layerValue);
}

/**
 * Sets the value for the propbank layer in a node. Value may consist of multiple propbank information separated via
 * '#' character. Each propbank value consists of argumentType and id info separated via '$' character.
 * @param layerValue New layer info
 */
void EnglishPropbankLayer::setLayerValue(const string &layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue, "#");
        for (const string &word : splitWords){
            items.emplace_back(Argument(word));
        }
    }
}
