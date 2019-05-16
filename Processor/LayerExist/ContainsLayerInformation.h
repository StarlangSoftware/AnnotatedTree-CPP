//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_CONTAINSLAYERINFORMATION_H
#define ANNOTATEDTREE_CONTAINSLAYERINFORMATION_H


#include "LeafListCondition.h"

class ContainsLayerInformation : public LeafListCondition{
private:
    ViewLayerType viewLayerType;
public:
    explicit ContainsLayerInformation(ViewLayerType viewLayerType);
    bool satisfies(vector<ParseNodeDrawable*> leafList) override;
};


#endif //ANNOTATEDTREE_CONTAINSLAYERINFORMATION_H
