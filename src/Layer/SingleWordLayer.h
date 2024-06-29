//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_SINGLEWORDLAYER_H
#define ANNOTATEDTREE_SINGLEWORDLAYER_H


#include "WordLayer.h"

/**
 * Abstract class for storing single word (single property per each word) in the node of the tree
 * @param <T> Type of the property for the word
 */
template <class T> class SingleWordLayer : public WordLayer{
public:
    void setLayerValue(const string& layerValue);
};

/**
 * Sets the property of the word
 * @param layerValue Layer info
 */
template<class T> void SingleWordLayer<T>::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
}

#endif //ANNOTATEDTREE_SINGLEWORDLAYER_H
