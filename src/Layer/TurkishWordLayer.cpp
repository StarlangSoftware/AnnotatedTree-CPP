//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "TurkishWordLayer.h"

/**
 * Constructor for the word layer for Turkish language. Sets the surface form.
 * @param layerValue Value for the word layer.
 */
TurkishWordLayer::TurkishWordLayer(const string& layerValue) : TargetLanguageWordLayer(layerValue) {
    layerName = "turkish";
}
