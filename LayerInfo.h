//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_LAYERINFO_H
#define ANNOTATEDTREE_LAYERINFO_H

#include <map>
#include <ViewLayerType.h>
#include <MorphologicalParse.h>
#include <MetamorphicParse.h>
#include "Layer/WordLayer.h"

using namespace std;
class LayerInfo {
private:
    map<ViewLayerType, WordLayer*> layers;
    string getMultiWordAt(ViewLayerType viewLayerType, int index, string layerName);
public:
    explicit LayerInfo(string info);
    LayerInfo() = default;
    void setLayerData(ViewLayerType viewLayer, string layerValue);
    void setMorphologicalAnalysis(MorphologicalParse parse);
    void setMetaMorphemes(MetamorphicParse parse);
    bool layerExists(ViewLayerType viewLayerType);
    ViewLayerType checkLayer(ViewLayerType viewLayer);
    int getNumberOfWords();
    string getTurkishWordAt(int index);
    int getNumberOfMeanings();
    string getSemanticAt(int index);
    string getShallowParseAt(int index);
};


#endif //ANNOTATEDTREE_LAYERINFO_H
