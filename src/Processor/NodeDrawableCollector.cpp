//
// Created by olcay on 2019-05-16.
//

#include "NodeDrawableCollector.h"

NodeDrawableCollector::NodeDrawableCollector(ParseNodeDrawable *rootNode, NodeDrawableCondition *condition) {
    this->rootNode = rootNode;
    this->condition = condition;
}

void NodeDrawableCollector::collectNodes(ParseNodeDrawable *parseNode, vector<ParseNodeDrawable *>& collected) const{
    if (condition == nullptr || condition->satisfies(parseNode)){
        collected.emplace_back(parseNode);
    }
    for (int i = 0; i < parseNode->numberOfChildren(); i++){
        collectNodes((ParseNodeDrawable*)parseNode->getChild(i), collected);
    }
}

vector<ParseNodeDrawable *> NodeDrawableCollector::collect() const{
    vector<ParseNodeDrawable*> result;
    collectNodes(rootNode, result);
    return result;
}
