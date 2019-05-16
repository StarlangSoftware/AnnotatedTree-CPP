//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithSymbol.h"

IsNodeWithSymbol::IsNodeWithSymbol(string symbol) {
    this->symbol = move(symbol);
}

bool IsNodeWithSymbol::satisfies(ParseNodeDrawable* parseNode) {
    if (parseNode->numberOfChildren() > 0){
        return parseNode->getData().to_string() == symbol;
    } else {
        return false;
    }
}
