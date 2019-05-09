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

#endif //ANNOTATEDTREE_SINGLEWORDLAYER_H
