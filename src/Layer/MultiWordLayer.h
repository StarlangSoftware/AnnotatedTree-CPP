//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_MULTIWORDLAYER_H
#define ANNOTATEDTREE_MULTIWORDLAYER_H


#include "WordLayer.h"

/**
 * Abstract class for storing multiple words (single property per each word) in the node of the tree
 * @param <T> Type of the property for the word
 */
template <class T> class MultiWordLayer : public WordLayer{
protected:
    vector<T> items;
public:
    T getItemAt(int index);
    int size();
    virtual void setLayerValue(const string& layerValue) = 0;
};

/**
 * Returns the item (word or its property) at position index.
 * @param index Position of the item (word or its property).
 * @return The item at position index.
 */
template<class T> T MultiWordLayer<T>::getItemAt(int index) {
    return items.at(index);
}

/**
 * Returns number of items (words) in the items array list.
 * @return Number of items (words) in the items array list.
 */
template<class T> int MultiWordLayer<T>::size() {
    return items.size();
}
#endif //ANNOTATEDTREE_MULTIWORDLAYER_H
