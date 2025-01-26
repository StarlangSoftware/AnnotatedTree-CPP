#include <utility>
#include <Dictionary/Word.h>
#include <vector>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "ShallowParseLayer.h"
#include <StringUtils.h>

/**
 * Constructor for the shallow parse layer. Sets shallow parse information for each word in
 * the node.
 * @param layerValue Layer value for the shallow parse information. Consists of shallow parse information
 *                   for every word.
 */
ShallowParseLayer::ShallowParseLayer(const string& layerValue) {
    this->layerName = "shallowParse";
    setLayerValue(layerValue);
}

/**
 * Sets the value for the shallow parse layer in a node. Value may consist of multiple shallow parse information
 * separated via space character. Each shallow parse value is a string.
 * @param layerValue New layer info
 */
void ShallowParseLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitParse = StringUtils::split(layerValue);
        items = splitParse;
    }
}
