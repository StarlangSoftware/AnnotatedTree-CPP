//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#ifndef ANNOTATEDTREE_ENGLISHWORDLAYER_H
#define ANNOTATEDTREE_ENGLISHWORDLAYER_H


#include "SourceLanguageWordLayer.h"

class EnglishWordLayer : public SourceLanguageWordLayer{
public:
    explicit EnglishWordLayer(const string& layerValue);
};

#endif //ANNOTATEDTREE_ENGLISHWORDLAYER_H
