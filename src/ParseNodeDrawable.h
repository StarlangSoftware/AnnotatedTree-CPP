//
// Created by Olcay Taner YILDIZ on 2019-05-12.
//

#ifndef ANNOTATEDTREE_PARSENODEDRAWABLE_H
#define ANNOTATEDTREE_PARSENODEDRAWABLE_H


#include <ParseNode.h>
#include "LayerInfo.h"
#include "ParseTreeSearchable.h"
#include "ParseNodeSearchable.h"

class ParseNodeDrawable : public ParseNode{
protected:
    LayerInfo* layers = nullptr;
    int depth;
public:
    ParseNodeDrawable(ParseNodeDrawable* parent, const string& line, bool isLeaf, int depth);
    explicit ParseNodeDrawable(const Symbol& data);
    ParseNodeDrawable(ParseNodeDrawable* parent, ParseNodeDrawable* child, const string& symbol);
    LayerInfo* getLayerInfo() const;
    Symbol getData() const;
    void clearLayers();
    void clearLayer(ViewLayerType layerType);
    void clearData();
    void setDataAndClearLayers(const Symbol& data);
    void setData(const Symbol& data);
    string headWord(ViewLayerType viewLayerType) const;
    string getLayerData() const;
    string getLayerData(ViewLayerType viewLayer) const;
    int getDepth() const;
    int structureAgreementCount(ParseNodeDrawable* parseNode) const;
    int glossAgreementCount(ParseNodeDrawable* parseNode, ViewLayerType viewLayerType) const;
    void updateDepths(int _depth);
    int maxDepth() const;
    string ancestorString() const;
    bool layerExists(ViewLayerType viewLayerType) const;
    bool isDummyNode() const;
    bool layerAll(ViewLayerType viewLayerType) const;
    string toTurkishSentence() const;
    void checkGazetteer(Gazetteer& gazetteer, const string& word);
    void generateParseNode(ParseNode* parseNode, bool surfaceForm) const;
    string to_string() const;
    bool satisfy(ParseNodeSearchable* node) const;
    vector<ParseNodeDrawable*> satisfy(const ParseTreeSearchable& tree);
};


#endif //ANNOTATEDTREE_PARSENODEDRAWABLE_H
