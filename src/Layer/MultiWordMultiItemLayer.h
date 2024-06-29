//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H
#define ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H

#include "MultiWordLayer.h"
#include "ViewLayerType.h"

/**
 * Abstract class for storing multiple words (multiple properties per each word) in the node of the tree
 * @param <T> Type of the property for the word
 */
template <class T> class MultiWordMultiItemLayer : public MultiWordLayer<T> {
public:
    virtual int getLayerSize(ViewLayerType viewLayer) const = 0;
    virtual string getLayerInfoAt(ViewLayerType viewLayer, int index) const = 0;
};


#endif //ANNOTATEDTREE_MULTIWORDMULTIITEMLAYER_H
