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

template<class T> T SingleWordMultiItemLayer<T>::getItemAt(int index) {
    return items.at(index);
}

template<class T> int SingleWordMultiItemLayer<T>::getLayerSize() {
    return items.size();
}

#endif //ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H
