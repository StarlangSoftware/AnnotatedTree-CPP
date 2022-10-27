//
// Created by olcay on 2019-05-08.
//

#include "WordLayer.h"

string WordLayer::getLayerValue() const{
    return layerValue;
}

string WordLayer::getLayerName() const{
    return layerName;
}

string WordLayer::getLayerDescription() const{
    return "{" + layerName + "=" + layerValue + "}";
}
