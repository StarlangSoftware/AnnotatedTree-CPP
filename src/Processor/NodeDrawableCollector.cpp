//
// Created by olcay on 2019-05-16.
//

#include "NodeDrawableCollector.h"

/**
 * Constructor for the NodeDrawableCollector class. NodeDrawableCollector's main aim is to collect a set of
 * ParseNode's from a subtree rooted at rootNode, where the ParseNode's satisfy a given NodeCondition, which is
 * implemented by other interface class.
 * @param rootNode Root node of the subtree
 * @param condition The condition interface for which all nodes in the subtree rooted at rootNode will be checked
 */
NodeDrawableCollector::NodeDrawableCollector(ParseNodeDrawable *rootNode, NodeDrawableCondition *condition) {
    this->rootNode = rootNode;
    this->condition = condition;
}

/**
 * Private recursive method to check all descendants of the parseNode, if they ever satisfy the given node condition
 * @param parseNode Root node of the subtree
 * @param collected The {@link ArrayList} where the collected ParseNode's will be stored.
 */
void NodeDrawableCollector::collectNodes(ParseNodeDrawable *parseNode, vector<ParseNodeDrawable *>& collected) const{
    if (condition == nullptr || condition->satisfies(parseNode)){
        collected.emplace_back(parseNode);
    }
    for (int i = 0; i < parseNode->numberOfChildren(); i++){
        collectNodes((ParseNodeDrawable*)parseNode->getChild(i), collected);
    }
}

/**
 * Collects and returns all ParseNodes satisfying the node condition.
 * @return All ParseNodes satisfying the node condition.
 */
vector<ParseNodeDrawable *> NodeDrawableCollector::collect() const{
    vector<ParseNodeDrawable*> result;
    collectNodes(rootNode, result);
    return result;
}
