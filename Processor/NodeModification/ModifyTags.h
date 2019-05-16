//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_MODIFYTAGS_H
#define ANNOTATEDTREE_MODIFYTAGS_H
#include "NodeModifier.h"

class ModifyTags : public NodeModifier{
public:
    void modifier(ParseNodeDrawable* parseNode) override;
};


#endif //ANNOTATEDTREE_MODIFYTAGS_H
