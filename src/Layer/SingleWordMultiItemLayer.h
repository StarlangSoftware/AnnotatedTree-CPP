//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H
#define ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H

#include "SingleWordLayer.h"

/**
 * Abstract class for storing single word (multiple properties per each word) in the node of the tree
 * @param <T> Type of the property for the word
 */
template <class T> class SingleWordMultiItemLayer : public SingleWordLayer<T> {
protected:
    vector<T> items;
public:
    T getItemAt(int index);
    int getLayerSize();
};

/**
 * Returns the property at position index for the word.
 * @param index Position of the property
 * @return The property at position index for the word.
 */
template<class T> T SingleWordMultiItemLayer<T>::getItemAt(int index) {
    return items.at(index);
}

/**
 * Returns the total number of properties for the word in the node.
 * @param viewLayer Not used.
 * @return Total number of properties for the word in the node.
 */
template<class T> int SingleWordMultiItemLayer<T>::getLayerSize() {
    return items.size();
}

#endif //ANNOTATEDTREE_SINGLEWORDMULTIITEMLAYER_H
