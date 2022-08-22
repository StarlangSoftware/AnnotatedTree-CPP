//
// Created by olcay on 2019-05-16.
//

#include "TreeModifier.h"

void TreeModifier::nodeModify(ParseNodeDrawable *parseNode) {
    nodeModifier->modifier(parseNode);
    for (int i = 0; i < parseNode->numberOfChildren(); i++){
        nodeModify((ParseNodeDrawable*)parseNode->getChild(i));
    }
}

void TreeModifier::modify() {
    nodeModify((ParseNodeDrawable*)parseTree->getRoot());
}

TreeModifier::TreeModifier(ParseTreeDrawable *parseTree, NodeModifier* nodeModifier) {
    this->parseTree = parseTree;
    this->nodeModifier = nodeModifier;
}
