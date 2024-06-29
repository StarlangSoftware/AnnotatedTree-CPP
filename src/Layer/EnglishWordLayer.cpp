//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "EnglishWordLayer.h"

/**
 * Constructor for the word layer for English language. Sets the surface form.
 * @param layerValue Value for the word layer.
 */
EnglishWordLayer::EnglishWordLayer(const string& layerValue) : SourceLanguageWordLayer(layerValue) {
    layerName = "english";
}
