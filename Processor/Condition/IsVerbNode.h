//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISVERBNODE_H
#define ANNOTATEDTREE_ISVERBNODE_H
#include "IsLeafNode.h"
#include <WordNet.h>

class IsVerbNode : public IsLeafNode{
private:
    WordNet wordNet;
public:
    explicit IsVerbNode(WordNet& wordNet);
    bool satisfies(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_ISVERBNODE_H
