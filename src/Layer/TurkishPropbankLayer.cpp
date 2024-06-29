#include <utility>

//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "TurkishPropbankLayer.h"

/**
 * Constructor for the Turkish propbank layer. Sets single semantic role information for multiple words in
 * the node.
 * @param layerValue Layer value for the propbank information. Consists of semantic role information
 *                   of multiple words.
 */
TurkishPropbankLayer::TurkishPropbankLayer(const string& layerValue) {
    layerName = "propbank";
    setLayerValue(layerValue);
}

/**
 * Sets the layer value for Turkish propbank layer. Converts the string form to an Argument.
 * @param layerValue New value for Turkish propbank layer.
 */
void TurkishPropbankLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    propbank = Argument(layerValue);
}

/**
 * Accessor for the propbank field.
 * @return Propbank field.
 */
Argument TurkishPropbankLayer::getArgument() const{
    return propbank;
}

/**
 * Another accessor for the propbank field.
 * @return String form of the propbank field.
 */
string TurkishPropbankLayer::getLayerValue() const{
    return propbank.getArgumentType() + "$" + propbank.getId();
}
