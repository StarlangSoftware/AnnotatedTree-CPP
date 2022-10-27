//
// Created by olcay on 2019-05-16.
//

#include "IsPunctuationNode.h"

bool IsPunctuationNode::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        return Word::isPunctuation(data) && data != "$";
    }
    return false;
}
