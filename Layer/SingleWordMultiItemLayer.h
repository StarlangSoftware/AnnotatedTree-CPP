//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H
#define ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H

#include "SingleWordLayer.h"

template <class T> class SingleWordMultiItemLayer : public SingleWordLayer<T> {
protected:
    vector<T> items;
public:
    T getItemAt(int index);
    int getLayerSize();
};

#endif //ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H
