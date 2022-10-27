//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_METAMORPHEMELAYER_H
#define ANNOTATEDTREE_METAMORPHEMELAYER_H


#include "MetaMorphemesMovedLayer.h"

class MetaMorphemeLayer : public MetaMorphemesMovedLayer {
public:
    explicit MetaMorphemeLayer(const string &layerValue);
    void setLayerValue(const MetamorphicParse& parse);
    string getLayerInfoFrom(int index) const;
    MetamorphicParse metaMorphemeRemoveFromIndex(int index);
};

#endif //ANNOTATEDTREE_METAMORPHEMELAYER_H
