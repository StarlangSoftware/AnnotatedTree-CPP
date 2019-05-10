#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "NERLayer.h"

NERLayer::NERLayer(string layerValue) {
    layerName = "namedEntity";
    setLayerValue(move(layerValue));
}

void NERLayer::setLayerValue(string layerValue) {
    this->layerValue = layerValue;
    namedEntity = getNamedEntityType(layerValue);
}

string NERLayer::getLayerValue() {
    return getNamedEntityType(namedEntity);
}
