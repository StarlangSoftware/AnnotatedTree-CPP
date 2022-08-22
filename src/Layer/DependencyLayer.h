//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_DEPENDENCYLAYER_H
#define ANNOTATEDTREE_DEPENDENCYLAYER_H


#include "SingleWordLayer.h"

class DependencyLayer : public SingleWordLayer<string>{
public:
    explicit DependencyLayer(const string &layerValue);
};


#endif //ANNOTATEDTREE_DEPENDENCYLAYER_H
