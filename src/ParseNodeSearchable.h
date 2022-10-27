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
    ParseNodeSearchable(ParseNodeSearchable* parent, XmlElement* node);
    SearchType getType(int index) const;
    string getValue(int index) const;
    ViewLayerType getViewLayerType(int index) const;
    bool isLeaf() const;
    int size() const;
};


#endif //ANNOTATEDTREE_PARSENODESEARCHABLE_H
