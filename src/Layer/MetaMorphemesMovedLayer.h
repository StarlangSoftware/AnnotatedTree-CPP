//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_METAMORPHEMESMOVEDLAYER_H
#define ANNOTATEDTREE_METAMORPHEMESMOVEDLAYER_H


#include <MetamorphicParse.h>
#include "MultiWordMultiItemLayer.h"

class MetaMorphemesMovedLayer : public MultiWordMultiItemLayer<MetamorphicParse> {
public:
    explicit MetaMorphemesMovedLayer(const string &layerValue);
    void setLayerValue(const string &layerValue) override;
    int getLayerSize(ViewLayerType viewLayer) const override;
    string getLayerInfoAt(ViewLayerType viewLayer, int index) const override;
};

#endif //ANNOTATEDTREE_METAMORPHEMESMOVEDLAYER_H
