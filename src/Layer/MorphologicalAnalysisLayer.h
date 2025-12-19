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
    void setLayerValue(const MorphologicalParse& parse);
    [[nodiscard]] int getLayerSize(ViewLayerType viewLayer) const override;
    [[nodiscard]] string getLayerInfoAt(ViewLayerType viewLayer, int index) const override;
    [[nodiscard]] bool isVerbal() const;
    [[nodiscard]] bool isNominal() const;
};

#endif //ANNOTATEDTREE_MORPHOLOGICALANALYSISLAYER_H
