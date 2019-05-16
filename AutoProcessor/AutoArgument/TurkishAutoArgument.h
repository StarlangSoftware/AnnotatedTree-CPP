//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_TURKISHAUTOARGUMENT_H
#define ANNOTATEDTREE_TURKISHAUTOARGUMENT_H


#include "AutoArgument.h"

class TurkishAutoArgument : public AutoArgument{
public:
    TurkishAutoArgument();
private:
    bool checkAncestors(ParseNode* parseNode, const string& name);
    bool checkAncestorsUntil(ParseNode* parseNode, const string& suffix);
protected:
    bool autoDetectArgument(ParseNodeDrawable* parseNode, ArgumentType argumentType);
};


#endif //ANNOTATEDTREE_TURKISHAUTOARGUMENT_H
