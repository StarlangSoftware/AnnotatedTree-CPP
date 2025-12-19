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
    [[nodiscard]] string getMultiWordAt(ViewLayerType viewLayerType, int index, const string& layerName) const;
    void updateMetaMorphemesMoved();
public:
    explicit LayerInfo(const string& info);
    LayerInfo() = default;
    ~LayerInfo();
    void setLayerData(ViewLayerType viewLayer, const string& layerValue);
    void setMorphologicalAnalysis(const MorphologicalParse& parse);
    void setMetaMorphemes(const MetamorphicParse& parse);
    [[nodiscard]] bool layerExists(ViewLayerType viewLayerType) const;
    [[nodiscard]] ViewLayerType checkLayer(ViewLayerType viewLayer) const;
    [[nodiscard]] int getNumberOfWords() const;
    [[nodiscard]] string getTurkishWordAt(int index) const;
    [[nodiscard]] int getNumberOfMeanings() const;
    [[nodiscard]] string getSemanticAt(int index) const;
    [[nodiscard]] string getShallowParseAt(int index) const;
    [[nodiscard]] Argument getArgument() const;
    [[nodiscard]] Argument getArgumentAt(int index) const;
    [[nodiscard]] MorphologicalParse getMorphologicalParseAt(int index) const;
    [[nodiscard]] MetamorphicParse getMetamorphicParseAt(int index) const;
    [[nodiscard]] string getMetaMorphemeAtIndex(int index) const;
    [[nodiscard]] string getMetaMorphemeFromIndex(int index) const;
    [[nodiscard]] int getLayerSize(ViewLayerType viewLayer) const;
    [[nodiscard]] string getLayerInfoAt(ViewLayerType viewLayer, int index) const;
    string getLayerDescription();
    [[nodiscard]] string getLayerData(ViewLayerType viewLayer) const;
    [[nodiscard]] string getRobustLayerData(ViewLayerType viewLayer) const;
    void removeLayer(ViewLayerType layerType);
    void metaMorphemeClear();
    void englishClear();
    void dependencyClear();
    void metaMorphemesMovedClear();
    void semanticClear();
    void englishSemanticClear();
    void morphologicalAnalysisClear();
    MetamorphicParse metaMorphemeRemove(int index);
    [[nodiscard]] bool isVerbal() const;
    [[nodiscard]] bool isNominal() const;
    [[nodiscard]] AnnotatedWord* toAnnotatedWord(int wordIndex) const;
};


#endif //ANNOTATEDTREE_LAYERINFO_H
