//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_ISNODEWITHPREDICATE_H
#define ANNOTATEDTREE_ISNODEWITHPREDICATE_H


#include "IsNodeWithSynSetId.h"

class IsNodeWithPredicate : public IsNodeWithSynSetId{
public:
    explicit IsNodeWithPredicate(const string& id);
    bool satisfies(ParseNodeDrawable* parseNode);
};


#endif //ANNOTATEDTREE_ISNODEWITHPREDICATE_H
