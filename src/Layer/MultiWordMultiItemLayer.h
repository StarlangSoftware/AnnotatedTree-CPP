//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H
#define ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H

#include "MultiWordLayer.h"
#include "ViewLayerType.h"

template <class T> class MultiWordMultiItemLayer : public MultiWordLayer<T> {
public:
    virtual int getLayerSize(ViewLayerType viewLayer) const = 0;
    virtual string getLayerInfoAt(ViewLayerType viewLayer, int index) const = 0;
};


#endif //ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H
