//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MultiWordLayer.h"

template<class T> T MultiWordLayer<T>::getItemAt(int index) {
    return items.at(index);
}

template<class T> int MultiWordLayer<T>::size() {
    return items.size();
}
