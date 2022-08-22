//
// Created by olcay on 2019-05-08.
//

#ifndef ANNOTATEDTREE_SOURCELANGUAGEWORDLAYER_H
#define ANNOTATEDTREE_SOURCELANGUAGEWORDLAYER_H


#include "SingleWordLayer.h"

class SourceLanguageWordLayer : public SingleWordLayer<string> {
public:
    explicit SourceLanguageWordLayer(const string& layerValue);
};

#endif //ANNOTATEDTREE_SOURCELANGUAGEWORDLAYER_H
