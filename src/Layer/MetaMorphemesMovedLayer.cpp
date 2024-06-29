//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MetaMorphemesMovedLayer.h"

/**
 * Constructor for the metaMorphemesMoved layer. Sets the metamorpheme information for multiple words in the node.
 * @param layerValue Layer value for the metaMorphemesMoved information. Consists of metamorpheme information of
 *                   multiple words separated via space character.
 */
MetaMorphemesMovedLayer::MetaMorphemesMovedLayer(const string &layerValue) {
    layerName = "metaMorphemesMoved";
    setLayerValue(layerValue);
}

/**
 * Sets the layer value to the string form of the given parse.
 * @param layerValue New metamorphic parse.
 */
void MetaMorphemesMovedLayer::setLayerValue(const string &layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector <string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MetamorphicParse(word));
        }
    }
}

/**
 * Returns the total number of metamorphemes in the words in the node.
 * @param viewLayer Not used.
 * @return Total number of metamorphemes in the words in the node.
 */
int MetaMorphemesMovedLayer::getLayerSize(ViewLayerType viewLayer) const{
    int size = 0;
    for (const MetamorphicParse& parse: items){
        size += parse.size();
    }
    return size;
}

/**
 * Returns the metamorpheme at position index in the metamorpheme list.
 * @param viewLayer Not used.
 * @param index Position in the metamorpheme list.
 * @return The metamorpheme at position index in the metamorpheme list.
 */
string MetaMorphemesMovedLayer::getLayerInfoAt(ViewLayerType viewLayer, int index) const{
    int size = 0;
    for (const MetamorphicParse& parse: items){
        if (index < size + parse.size()){
            return parse.getMetaMorpheme(index - size);
        }
        size += parse.size();
    }
    return "";
}

