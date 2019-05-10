//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_TURKISHSEMANTICLAYER_H
#define ANNOTATEDTREE_TURKISHSEMANTICLAYER_H


#include "MultiWordLayer.h"

class TurkishSemanticLayer : public MultiWordLayer<string>{
public:
    explicit TurkishSemanticLayer(string layerValue);
    void setLayerValue(const string& layerValue);
};


#endif //ANNOTATEDTREE_TURKISHSEMANTICLAYER_H
