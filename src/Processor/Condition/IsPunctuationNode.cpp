//
// Created by olcay on 2019-05-16.
//

#include "IsPunctuationNode.h"

/**
 * Checks if the node is a leaf node and contains punctuation as the data.
 * @param parseNode Parse node to check.
 * @return True if the node is a leaf node and contains punctuation as the data, false otherwise.
 */
bool IsPunctuationNode::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        return Word::isPunctuation(data) && data != "$";
    }
    return false;
}
