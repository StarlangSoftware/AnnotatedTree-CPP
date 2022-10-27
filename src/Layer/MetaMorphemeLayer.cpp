//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MetaMorphemeLayer.h"

MetaMorphemeLayer::MetaMorphemeLayer(const string &layerValue) : MetaMorphemesMovedLayer(layerValue) {
    layerName = "metaMorphemes";
}

void MetaMorphemeLayer::setLayerValue(const MetamorphicParse& parse) {
    layerValue = parse.to_string();
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MetamorphicParse(word));
        }
    }
}

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
