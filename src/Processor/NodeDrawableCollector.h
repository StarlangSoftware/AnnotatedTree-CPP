//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_NODEDRAWABLECOLLECTOR_H
#define ANNOTATEDTREE_NODEDRAWABLECOLLECTOR_H


#include "Condition/NodeDrawableCondition.h"

class NodeDrawableCollector {
private:
    NodeDrawableCondition* condition = nullptr;
    ParseNodeDrawable* rootNode = nullptr;
    void collectNodes(ParseNodeDrawable* parseNode, vector<ParseNodeDrawable*>& collected) const;
public:
    NodeDrawableCollector(ParseNodeDrawable* rootNode, NodeDrawableCondition* condition);
    vector<ParseNodeDrawable*> collect() const;
};


#endif //ANNOTATEDTREE_NODEDRAWABLECOLLECTOR_H
