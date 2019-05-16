//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNODEWITHSYNSETID_H
#define ANNOTATEDTREE_ISNODEWITHSYNSETID_H


#include "IsLeafNode.h"

class IsNodeWithSynSetId : public IsLeafNode{
private:
    string id;
public:
    explicit IsNodeWithSynSetId(string id);
    bool satisfies(ParseNodeDrawable* parseNode);
};


#endif //ANNOTATEDTREE_ISNODEWITHSYNSETID_H
