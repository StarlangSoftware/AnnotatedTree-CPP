//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H
#define ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H

#include <vector>
#include <ViewLayerType.h>
#include "Word.h"
#include "MultiWordLayer.h"

class TargetLanguageWordLayer : public MultiWordLayer<string>{
public:
    explicit TargetLanguageWordLayer(const string& layerValue);
    void setLayerValue(const string& layerValue) override;
    int getLayerSize(ViewLayerType viewLayer);
    string getLayerInfoAt(ViewLayerType viewLayer, int index);
};

TargetLanguageWordLayer::TargetLanguageWordLayer(const string& layerValue) {
    setLayerValue(layerValue);
}

void TargetLanguageWordLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        items.insert(items.end(), splitWords.begin(), splitWords.end());
    }
}

int TargetLanguageWordLayer::getLayerSize(ViewLayerType viewLayer) {
    return 0;
}

string TargetLanguageWordLayer::getLayerInfoAt(ViewLayerType viewLayer, int index) {
    return "";
}


#endif //ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H
