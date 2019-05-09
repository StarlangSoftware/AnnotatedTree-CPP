//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_METAMORPHEMELAYER_H
#define ANNOTATEDTREE_METAMORPHEMELAYER_H


#include "MetaMorphemesMovedLayer.h"

class MetaMorphemeLayer : public MetaMorphemesMovedLayer {
public:
    explicit MetaMorphemeLayer(const string &layerValue);
    void setLayerValue(MetamorphicParse parse);
    string getLayerInfoFrom(int index);
    MetamorphicParse metaMorphemeRemoveFromIndex(int index);
};

#endif //ANNOTATEDTREE_METAMORPHEMELAYER_H
