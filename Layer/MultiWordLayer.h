//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_MULTIWORDLAYER_H
#define ANNOTATEDTREE_MULTIWORDLAYER_H


#include "WordLayer.h"

template <class T> class MultiWordLayer : public WordLayer{
protected:
    vector<T> items;
public:
    T getItemAt(int index);
    int size();
    virtual void setLayerValue(const string& layerValue) = 0;
};

#endif //ANNOTATEDTREE_MULTIWORDLAYER_H
