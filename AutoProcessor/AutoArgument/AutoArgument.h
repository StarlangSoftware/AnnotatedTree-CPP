//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_AUTOARGUMENT_H
#define ANNOTATEDTREE_AUTOARGUMENT_H


#include <ViewLayerType.h>
#include <ArgumentType.h>
#include <Frameset.h>
#include "../../ParseNodeDrawable.h"
#include "../../ParseTreeDrawable.h"

class AutoArgument {
protected:
    ViewLayerType secondLanguage;
    virtual bool autoDetectArgument(ParseNodeDrawable* parseNode, ArgumentType argumentType) = 0;
    explicit AutoArgument(ViewLayerType secondLanguage);
public:
    void autoArgument(ParseTreeDrawable* parseTree, Frameset frameset);
};


#endif //ANNOTATEDTREE_AUTOARGUMENT_H
