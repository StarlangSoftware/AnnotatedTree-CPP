//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "EnglishSemanticLayer.h"

/**
 * Constructor for the semantic layer for English language. Sets the layer value to the synset id defined in English
 * WordNet.
 * @param layerValue Value for the English semantic layer.
 */
EnglishSemanticLayer::EnglishSemanticLayer(const string &layerValue) {
    layerName = "englishSemantics";
    setLayerValue(layerValue);
}
