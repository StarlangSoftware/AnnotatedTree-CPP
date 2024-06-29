//
// Created by olcay on 2019-05-08.
//

#include "WordLayer.h"

/**
 * Accessor for the layerValue attribute.
 * @return LayerValue attribute.
 */
string WordLayer::getLayerValue() const{
    return layerValue;
}

/**
 * Accessor for the layerName attribute.
 * @return LayerName attribute.
 */
string WordLayer::getLayerName() const{
    return layerName;
}

/**
 * Returns string form of the word layer.
 * @return String form of the word layer.
 */
string WordLayer::getLayerDescription() const{
    return "{" + layerName + "=" + layerValue + "}";
}
