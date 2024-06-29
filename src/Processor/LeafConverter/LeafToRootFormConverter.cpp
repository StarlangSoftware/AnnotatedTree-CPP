//
// Created by olcay on 2019-05-16.
//

#include "LeafToRootFormConverter.h"

/**
 * Converts the data in the leaf node to string. If there are multiple words in the leaf node, they are concatenated
 * with space.
 * @param parseNodeDrawable Node to be converted to string.
 * @return String form of the data. If there are multiple words in the leaf node, they are concatenated
 * with space.
 */
string LeafToRootFormConverter::leafConverter(ParseNodeDrawable *parseNodeDrawable) const{
    LayerInfo* layerInfo = parseNodeDrawable->getLayerInfo();
    string rootWords = " ";
        for (int i = 0; i < layerInfo->getNumberOfWords(); i++) {
            string root = layerInfo->getMorphologicalParseAt(i).getWord()->getName();
            if (!root.empty()){
                rootWords.append(" ").append(root);
            }
        }
    return rootWords;
}
