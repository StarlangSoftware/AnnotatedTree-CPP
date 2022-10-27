//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithSymbol.h"

IsNodeWithSymbol::IsNodeWithSymbol(const string& symbol) {
    this->symbol = symbol;
}

bool IsNodeWithSymbol::satisfies(ParseNodeDrawable* parseNode) const{
    if (parseNode->numberOfChildren() > 0){
        return parseNode->getData().to_string() == symbol;
    } else {
        return false;
    }
}
