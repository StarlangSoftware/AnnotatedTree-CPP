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

template<class T> T MultiWordLayer<T>::getItemAt(int index) {
    return items.at(index);
}

template<class T> int MultiWordLayer<T>::size() {
    return items.size();
}
#endif //ANNOTATEDTREE_MULTIWORDLAYER_H
