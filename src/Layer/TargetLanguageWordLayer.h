//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H
#define ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H

#include <vector>
#include <ViewLayerType.h>
#include "Dictionary/Word.h"
#include "MultiWordLayer.h"

class TargetLanguageWordLayer : public MultiWordLayer<string>{
public:
    explicit TargetLanguageWordLayer(const string& layerValue);
    void setLayerValue(const string& layerValue) override;
    int getLayerSize(ViewLayerType viewLayer) const;
    string getLayerInfoAt(ViewLayerType viewLayer, int index) const;
};

#endif //ANNOTATEDTREE_TARGETLANGUAGEWORDLAYER_H
