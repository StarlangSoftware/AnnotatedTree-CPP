//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_ENGLISHPROPBANKLAYER_H
#define ANNOTATEDTREE_ENGLISHPROPBANKLAYER_H


#include <Argument.h>
#include "Dictionary/Word.h"
#include <vector>
#include "SingleWordMultiItemLayer.h"

class EnglishPropbankLayer : public SingleWordMultiItemLayer<Argument>{
public:
    explicit EnglishPropbankLayer(const string &layerValue);
    void setLayerValue(const string &layerValue);
};

#endif //ANNOTATEDTREE_ENGLISHPROPBANKLAYER_H
