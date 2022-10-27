//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_LAYERINFO_H
#define ANNOTATEDTREE_LAYERINFO_H

#include <map>
#include <AnnotatedWord.h>
#include <ViewLayerType.h>
#include <MorphologicalParse.h>
#include <MetamorphicParse.h>
#include <Argument.h>
#include "Layer/WordLayer.h"

using namespace std;
class LayerInfo {
private:
    map<ViewLayerType, WordLayer*> layers;
    string getMultiWordAt(ViewLayerType viewLayerType, int index, const string& layerName) const;
    void updateMetaMorphemesMoved();
public:
    explicit LayerInfo(const string& info);
    LayerInfo() = default;
    ~LayerInfo();
    void setLayerData(ViewLayerType viewLayer, const string& layerValue);
    void setMorphologicalAnalysis(const MorphologicalParse& parse);
    void setMetaMorphemes(const MetamorphicParse& parse);
    bool layerExists(ViewLayerType viewLayerType) const;
    ViewLayerType checkLayer(ViewLayerType viewLayer) const;
    int getNumberOfWords() const;
    string getTurkishWordAt(int index) const;
    int getNumberOfMeanings() const;
    string getSemanticAt(int index) const;
    string getShallowParseAt(int index) const;
    Argument getArgument() const;
    Argument getArgumentAt(int index) const;
    MorphologicalParse getMorphologicalParseAt(int index) const;
    MetamorphicParse getMetamorphicParseAt(int index) const;
    string getMetaMorphemeAtIndex(int index) const;
    string getMetaMorphemeFromIndex(int index) const;
    int getLayerSize(ViewLayerType viewLayer) const;
    string getLayerInfoAt(ViewLayerType viewLayer, int index) const;
    string getLayerDescription();
    string getLayerData(ViewLayerType viewLayer) const;
    string getRobustLayerData(ViewLayerType viewLayer) const;
    void removeLayer(ViewLayerType layerType);
    void metaMorphemeClear();
    void englishClear();
    void dependencyClear();
    void metaMorphemesMovedClear();
    void semanticClear();
    void englishSemanticClear();
    void morphologicalAnalysisClear();
    MetamorphicParse metaMorphemeRemove(int index);
    bool isVerbal() const;
    bool isNominal() const;
    AnnotatedWord* toAnnotatedWord(int wordIndex) const;
};


#endif //ANNOTATEDTREE_LAYERINFO_H
