//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#ifndef ANNOTATEDTREE_TURKISHPROPBANKLAYER_H
#define ANNOTATEDTREE_TURKISHPROPBANKLAYER_H


#include <Argument.h>
#include "SingleWordLayer.h"

class TurkishPropbankLayer : public SingleWordLayer<Argument>{
private:
    Argument propbank = Argument("");
public:
    explicit TurkishPropbankLayer(string layerValue);
    void setLayerValue(string layerValue);
    Argument getArgument();
    string getLayerValue();
};


#endif //ANNOTATEDTREE_TURKISHPROPBANKLAYER_H
