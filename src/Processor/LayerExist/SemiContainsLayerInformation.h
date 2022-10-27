//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_SEMICONTAINSLAYERINFORMATION_H
#define ANNOTATEDTREE_SEMICONTAINSLAYERINFORMATION_H


#include "LeafListCondition.h"

class SemiContainsLayerInformation : public LeafListCondition{
private:
    ViewLayerType viewLayerType;
public:
    explicit SemiContainsLayerInformation(ViewLayerType viewLayerType);
    bool satisfies(const vector<ParseNodeDrawable*>& leafList) const override;
};


#endif //ANNOTATEDTREE_SEMICONTAINSLAYERINFORMATION_H
