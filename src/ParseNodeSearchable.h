//
// Created by olcay on 2019-05-13.
//

#ifndef ANNOTATEDTREE_PARSENODESEARCHABLE_H
#define ANNOTATEDTREE_PARSENODESEARCHABLE_H
#include <ParseNode.h>
#include <ViewLayerType.h>
#include "SearchType.h"
#include "XmlElement.h"

class ParseNodeSearchable : public ParseNode{
private:
    vector<SearchType> searchTypes;
    vector<ViewLayerType> viewLayerTypes;
    vector<string> searchValues;
    bool isLeafNode = false;
public:
    ParseNodeSearchable(ParseNodeSearchable* parent, const XmlElement* node);
    [[nodiscard]] SearchType getType(int index) const;
    [[nodiscard]] string getValue(int index) const;
    [[nodiscard]] ViewLayerType getViewLayerType(int index) const;
    [[nodiscard]] bool isLeaf() const;
    [[nodiscard]] int size() const;
};


#endif //ANNOTATEDTREE_PARSENODESEARCHABLE_H
