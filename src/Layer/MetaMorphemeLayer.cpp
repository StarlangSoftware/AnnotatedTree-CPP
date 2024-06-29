//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MetaMorphemeLayer.h"

/**
 * Constructor for the metamorpheme layer. Sets the metamorpheme information for multiple words in the node.
 * @param layerValue Layer value for the metamorpheme information. Consists of metamorpheme information of multiple
 *                   words separated via space character.
 */
MetaMorphemeLayer::MetaMorphemeLayer(const string &layerValue) : MetaMorphemesMovedLayer(layerValue) {
    layerName = "metaMorphemes";
}

/**
 * Sets the layer value to the string form of the given parse.
 * @param parse New metamorphic parse.
 */
void MetaMorphemeLayer::setLayerValue(const MetamorphicParse& parse) {
    layerValue = parse.to_string();
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MetamorphicParse(word));
        }
    }
}

/**
 * Constructs metamorpheme information starting from the position index.
 * @param index Position of the morpheme to start.
 * @return Metamorpheme information starting from the position index.
 */
string MetaMorphemeLayer::getLayerInfoFrom(int index) const{
    int size = 0;
    for (const MetamorphicParse& parse: items){
        if (index < size + parse.size()){
            string result = parse.getMetaMorpheme(index - size);
            index++;
            while (index < size + parse.size()){
                result.append("+" + parse.getMetaMorpheme(index - size));
                index++;
            }
            return result;
        }
        size += parse.size();
    }
    return "";
}

/**
 * Removes metamorphemes from the given index. Index shows the position of the metamorpheme in the metamorphemes list.
 * @param index Position of the metamorpheme from which the other metamorphemes will be removed.
 * @return New metamorphic parse not containing the removed parts.
 */
MetamorphicParse MetaMorphemeLayer::metaMorphemeRemoveFromIndex(int index) {
    if (index >= 0 && index < getLayerSize(ViewLayerType::META_MORPHEME)){
        int size = 0;
        for (MetamorphicParse parse: items){
            if (index < size + parse.size()){
                parse.removeMetaMorphemeFromIndex(index - size);
                return parse;
            }
            size += parse.size();
        }
    }
}
