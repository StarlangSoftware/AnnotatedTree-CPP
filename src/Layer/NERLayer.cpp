#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "NERLayer.h"

/**
 * Constructor for the named entity layer. Sets single named entity information for multiple words in
 * the node.
 * @param layerValue Layer value for the named entity information. Consists of single named entity information
 *                   of multiple words.
 */
NERLayer::NERLayer(const string& layerValue) {
    layerName = "namedEntity";
    setLayerValue(layerValue);
}

/**
 * Sets the layer value for Named Entity layer. Converts the string form to a named entity.
 * @param layerValue New value for Named Entity layer.
 */
void NERLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    namedEntity = getNamedEntityType(layerValue);
}

/**
 * Get the string form of the named entity value. Converts named entity type to string form.
 * @return String form of the named entity value.
 */
string NERLayer::getLayerValue() const{
    return getNamedEntityType(namedEntity);
}
