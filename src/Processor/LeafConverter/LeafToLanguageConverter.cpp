//
// Created by olcay on 2019-05-16.
//

#include "LeafToLanguageConverter.h"

/**
 * Converts the data in the leaf node to string, except shortcuts to parentheses are converted to its normal forms,
 * '*', '0', '-NONE-' are converted to empty string.
 * @param leafNode Node to be converted to string.
 * @return String form of the data, except shortcuts to parentheses are converted to its normal forms,
 * '*', '0', '-NONE-' are converted to empty string.
 */
string LeafToLanguageConverter::leafConverter(ParseNodeDrawable *leafNode) const{
    string layerData = leafNode->getLayerData(viewLayerType);
    string parentLayerData = ((ParseNodeDrawable*)leafNode->getParent())->getLayerData(viewLayerType);
    if (!layerData.empty()){
        if (layerData.find('*') != string::npos || (layerData == "0" && parentLayerData == "-NONE-")){
            return "";
        } else {
            return " " + layerData;
        }
    } else {
        return "";
    }
}
