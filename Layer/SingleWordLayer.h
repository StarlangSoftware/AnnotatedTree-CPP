//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_SINGLEWORDLAYER_H
#define ANNOTATEDTREE_SINGLEWORDLAYER_H


#include "WordLayer.h"

template <class T> class SingleWordLayer : public WordLayer{
public:
    void setLayerValue(const string& layerValue);
};

template<class T> void SingleWordLayer<T>::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
}

#endif //ANNOTATEDTREE_SINGLEWORDLAYER_H
