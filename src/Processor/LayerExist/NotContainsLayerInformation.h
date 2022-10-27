//
// Created by olcay on 2019-05-16.
//

#ifndef ANNOTATEDTREE_NOTCONTAINSLAYERINFORMATION_H
#define ANNOTATEDTREE_NOTCONTAINSLAYERINFORMATION_H


#include "LeafListCondition.h"

class NotContainsLayerInformation : public LeafListCondition{
private:
    ViewLayerType viewLayerType;
public:
    explicit NotContainsLayerInformation(ViewLayerType viewLayerType);
    bool satisfies(const vector<ParseNodeDrawable*>& leafList) const override;
};


#endif //ANNOTATEDTREE_NOTCONTAINSLAYERINFORMATION_H
