//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_LEAFLISTCONDITION_H
#define ANNOTATEDTREE_LEAFLISTCONDITION_H


#include "../../ParseNodeDrawable.h"

class LeafListCondition {
    virtual bool satisfies(vector<ParseNodeDrawable*> leafList) = 0;
};


#endif //ANNOTATEDTREE_LEAFLISTCONDITION_H
