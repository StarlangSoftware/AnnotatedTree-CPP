#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "NERLayer.h"

NERLayer::NERLayer(const string& layerValue) {
    layerName = "namedEntity";
    setLayerValue(layerValue);
}

void NERLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    namedEntity = getNamedEntityType(layerValue);
}

string NERLayer::getLayerValue() const{
    return getNamedEntityType(namedEntity);
}
