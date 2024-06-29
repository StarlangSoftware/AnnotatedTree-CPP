//
// Created by olcay on 2019-05-16.
//

#include "IsNodeWithSymbol.h"

/**
 * Stores the symbol to check.
 * @param symbol Symbol to check
 */
IsNodeWithSymbol::IsNodeWithSymbol(const string& symbol) {
    this->symbol = symbol;
}

/**
 * Checks if the tag of the parse node is equal to the given symbol.
 * @param parseNode Parse node to check.
 * @return True if the tag of the parse node is equal to the given symbol, false otherwise.
 */
bool IsNodeWithSymbol::satisfies(ParseNodeDrawable* parseNode) const{
    if (parseNode->numberOfChildren() > 0){
        return parseNode->getData().to_string() == symbol;
    } else {
        return false;
    }
}
