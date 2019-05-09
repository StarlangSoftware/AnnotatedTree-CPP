//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_ENGLISHSEMANTICLAYER_H
#define ANNOTATEDTREE_ENGLISHSEMANTICLAYER_H


#include "SingleWordLayer.h"

class EnglishSemanticLayer : public SingleWordLayer<string> {
public:
    explicit EnglishSemanticLayer(const string &layerValue);
};

#endif //ANNOTATEDTREE_ENGLISHSEMANTICLAYER_H
