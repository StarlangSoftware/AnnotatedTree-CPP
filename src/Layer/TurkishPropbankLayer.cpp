#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "TurkishPropbankLayer.h"

TurkishPropbankLayer::TurkishPropbankLayer(const string& layerValue) {
    layerName = "propbank";
    setLayerValue(layerValue);
}

void TurkishPropbankLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    propbank = Argument(layerValue);
}

Argument TurkishPropbankLayer::getArgument() const{
    return propbank;
}

string TurkishPropbankLayer::getLayerValue() const{
    return propbank.getArgumentType() + "$" + propbank.getId();
}
