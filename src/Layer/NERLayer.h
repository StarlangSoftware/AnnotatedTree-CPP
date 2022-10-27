//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_NERLAYER_H
#define ANNOTATEDTREE_NERLAYER_H


#include <NamedEntityType.h>
#include "SingleWordLayer.h"

class NERLayer : public SingleWordLayer<NamedEntityType>{
private:
    NamedEntityType namedEntity;
public:
    explicit NERLayer(const string& layerValue);
    void setLayerValue(const string& layerValue);
    string getLayerValue() const;
};


#endif //ANNOTATEDTREE_NERLAYER_H
