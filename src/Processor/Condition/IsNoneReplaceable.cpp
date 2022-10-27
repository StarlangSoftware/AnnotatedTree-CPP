//
// Created by olcay on 2019-05-16.
//

#include "IsNoneReplaceable.h"

bool IsNoneReplaceable::satisfies(ParseNodeDrawable *parseNode){
    if (IsLeafNode::satisfies(parseNode)){
        string data = parseNode->getLayerData(ViewLayerType::ENGLISH_WORD);
        string parentData = parseNode->getParent()->getData().getName();
        if (parentData == "DT"){
            return data == "the";
        } else {
            if (parentData == "IN"){
                return data == "in" || data == "than" || data == "from" || data == "on" || data == "with" || data == "of" || data == "at" || data == "if" || data == "by";
            } else {
                if (parentData == "TO"){
                    return data == "to";
                } else {
                    if (parentData == "VBZ"){
                        return data == "has" || data == "does" || data == "is" || data == "'s";
                    } else {
                        if (parentData == "MD"){
                            return data == "will" || data == "'d" || data == "'ll" || data == "ca" || data == "can" || data == "could" || data == "would" || data == "should" || data == "wo" || data == "may" || data == "might";
                        } else {
                            if (parentData == "VBP"){
                                return data == "'re" || data == "is" || data == "are" || data == "am" || data == "'m" || data == "do" || data == "have" || data == "has" || data == "'ve";
                            } else {
                                if (parentData == "VBD"){
                                    return data == "had" || data == "did" || data == "were" || data == "was";
                                } else {
                                    if (parentData == "VBN"){
                                        return data == "been";
                                    } else {
                                        if (parentData == "VB"){
                                            return data == "have" || data == "be";
                                        } else {
                                            if (parentData == "RB"){
                                                return data == "n't" || data == "not";
                                            } else {
                                                if (parentData == "POS"){
                                                    return data == "'s" || data == "'";
                                                } else {
                                                    if (parentData == "WP"){
                                                        return data == "who" || data == "where" || data == "which" || data == "what" || data == "why";
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
