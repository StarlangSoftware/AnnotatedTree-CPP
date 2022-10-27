//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MetaMorphemesMovedLayer.h"

MetaMorphemesMovedLayer::MetaMorphemesMovedLayer(const string &layerValue) {
    layerName = "metaMorphemesMoved";
    setLayerValue(layerValue);
}

void MetaMorphemesMovedLayer::setLayerValue(const string &layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector <string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MetamorphicParse(word));
        }
    }
}

int MetaMorphemesMovedLayer::getLayerSize(ViewLayerType viewLayer) const{
    int size = 0;
    for (const MetamorphicParse& parse: items){
        size += parse.size();
    }
    return size;
}

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

