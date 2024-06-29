//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "PersianWordLayer.h"

/**
 * Constructor for the word layer for Persian language. Sets the surface form.
 * @param layerValue Value for the word layer.
 */
PersianWordLayer::PersianWordLayer(const string& layerValue) : TargetLanguageWordLayer(layerValue) {
    layerName = "persian";
}
