//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "SingleWordMultiItemLayer.h"

template<class T> T SingleWordMultiItemLayer<T>::getItemAt(int index) {
    return items.at(index);
}

template<class T> int SingleWordMultiItemLayer<T>::getLayerSize() {
    return items.size();
}
