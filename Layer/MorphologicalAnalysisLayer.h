//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_MORPHOLOGICALANALYSISLAYER_H
#define ANNOTATEDTREE_MORPHOLOGICALANALYSISLAYER_H


#include <MorphologicalParse.h>
#include "MultiWordMultiItemLayer.h"

class MorphologicalAnalysisLayer : public MultiWordMultiItemLayer<MorphologicalParse> {
public:
    explicit MorphologicalAnalysisLayer(const string& layerValue);
    void setLayerValue(const string& layerValue) override;
    void setLayerValue(MorphologicalParse parse);
    int getLayerSize(ViewLayerType viewLayer) override;
    string getLayerInfoAt(ViewLayerType viewLayer, int index) override;
    bool isVerbal();
    bool isNominal();
};

#endif //ANNOTATEDTREE_MORPHOLOGICALANALYSISLAYER_H
