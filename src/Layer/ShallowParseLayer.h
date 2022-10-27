//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_SHALLOWPARSELAYER_H
#define ANNOTATEDTREE_SHALLOWPARSELAYER_H


#include "MultiWordLayer.h"

class ShallowParseLayer : public MultiWordLayer<string> {
public:
    explicit ShallowParseLayer(const string& layerValue);
    void setLayerValue(const string& layerValue);
};


#endif //ANNOTATEDTREE_SHALLOWPARSELAYER_H
