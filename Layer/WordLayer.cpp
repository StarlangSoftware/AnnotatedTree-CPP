//
// Created by olcay on 2019-05-08.
//

#include "WordLayer.h"

string WordLayer::getLayerValue() {
    return layerValue;
}

string WordLayer::getLayerName() {
    return layerName;
}

string WordLayer::getLayerDescription() {
    return "{" + layerName + "=" + layerValue + "}";
}
