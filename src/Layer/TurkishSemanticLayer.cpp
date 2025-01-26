//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include <vector>
#include "Dictionary/Word.h"
#include "TurkishSemanticLayer.h"
#include <StringUtils.h>

/**
 * Constructor for the Turkish semantic layer. Sets semantic information for each word in
 * the node.
 * @param layerValue Layer value for the Turkish semantic information. Consists of semantic (Turkish synset id)
 *                   information for every word.
 */
TurkishSemanticLayer::TurkishSemanticLayer(const string& layerValue) {
    this->layerName = "semantics";
    setLayerValue(layerValue);
}

/**
 * Sets the value for the Turkish semantic layer in a node. Value may consist of multiple sense information
 * separated via '$' character. Each sense value is a string representing the synset id of the sense.
 * @param layerValue New layer info
 */
void TurkishSemanticLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitMeanings = StringUtils::split(layerValue, "$");
        this->items = splitMeanings;
    }
}
