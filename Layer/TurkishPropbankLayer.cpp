#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "TurkishPropbankLayer.h"

TurkishPropbankLayer::TurkishPropbankLayer(string layerValue) {
    layerName = "propbank";
    setLayerValue(move(layerValue));
}

void TurkishPropbankLayer::setLayerValue(string layerValue) {
    this->layerValue = layerValue;
    propbank = Argument(layerValue);
}

Argument TurkishPropbankLayer::getArgument() {
    return propbank;
}

string TurkishPropbankLayer::getLayerValue() {
    return propbank.getArgumentType() + "$" + propbank.getId();
}
