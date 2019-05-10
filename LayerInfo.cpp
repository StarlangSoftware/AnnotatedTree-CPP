//
// Created by Olcay Taner YILDIZ on 2019-05-10.
//

#include "LayerInfo.h"
#include "Layer/TurkishWordLayer.h"
#include "Layer/PersianWordLayer.h"
#include "Layer/EnglishWordLayer.h"
#include "Layer/MorphologicalAnalysisLayer.h"
#include "Layer/MetaMorphemeLayer.h"
#include "Layer/DependencyLayer.h"
#include "Layer/TurkishSemanticLayer.h"
#include "Layer/NERLayer.h"
#include "Layer/TurkishPropbankLayer.h"
#include "Layer/EnglishPropbankLayer.h"
#include "Layer/EnglishSemanticLayer.h"
#include "Layer/ShallowParseLayer.h"
#include <vector>
#include <Word.h>

LayerInfo::LayerInfo(string info) {
    vector<string> splitLayers = Word::split(move(info), "[{}]");
    for (const string &layer:splitLayers){
        if (layer.empty())
            continue;
        string layerType = layer.substr(0, layer.find_first_of('='));
        string layerValue = layer.substr(layer.find_first_of('=') + 1);
        if (layerType == "turkish"){
            layers.emplace(ViewLayerType::TURKISH_WORD, new TurkishWordLayer(layerValue));
        } else {
            if (layerType == "persian"){
                layers.emplace(ViewLayerType::PERSIAN_WORD, new PersianWordLayer(layerValue));
            } else {
                if (layerType == "english"){
                    layers.emplace(ViewLayerType::ENGLISH_WORD, new EnglishWordLayer(layerValue));
                } else {
                    if (layerType == "morphologicalAnalysis"){
                        layers.emplace(ViewLayerType::INFLECTIONAL_GROUP, new MorphologicalAnalysisLayer(layerValue));
                        layers.emplace(ViewLayerType::PART_OF_SPEECH, new MorphologicalAnalysisLayer(layerValue));
                    } else {
                        if (layerType == "metaMorphemes"){
                            layers.emplace(ViewLayerType::META_MORPHEME, new MetaMorphemeLayer(layerValue));
                        } else {
                            if (layerType == "metaMorphemesMoved"){
                                layers.emplace(ViewLayerType::META_MORPHEME_MOVED, new MetaMorphemesMovedLayer(layerValue));
                            } else {
                                if (layerType == "dependency"){
                                    layers.emplace(ViewLayerType::DEPENDENCY, new DependencyLayer(layerValue));
                                } else {
                                    if (layerType == "semantics"){
                                        layers.emplace(ViewLayerType::SEMANTICS, new TurkishSemanticLayer(layerValue));
                                    } else {
                                        if (layerType == "namedEntity"){
                                            layers.emplace(ViewLayerType::NER, new NERLayer(layerValue));
                                        } else {
                                            if (layerType == "propBank"){
                                                layers.emplace(ViewLayerType::PROPBANK, new TurkishPropbankLayer(layerValue));
                                            } else {
                                                if (layerType == "englishPropbank"){
                                                    layers.emplace(ViewLayerType::ENGLISH_PROPBANK, new EnglishPropbankLayer(layerValue));
                                                } else {
                                                    if (layerType == "englishSemantics"){
                                                        layers.emplace(ViewLayerType::ENGLISH_SEMANTICS, new EnglishSemanticLayer(layerValue));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void LayerInfo::setLayerData(ViewLayerType viewLayer, string layerValue) {
    switch (viewLayer){
        case ViewLayerType::PERSIAN_WORD:
            layers.emplace(ViewLayerType::PERSIAN_WORD, new PersianWordLayer(layerValue));
            layers.erase(ViewLayerType::SEMANTICS);
            break;
        case ViewLayerType::TURKISH_WORD:
            layers.emplace(ViewLayerType::TURKISH_WORD, new TurkishWordLayer(layerValue));
            layers.erase(ViewLayerType::INFLECTIONAL_GROUP);
            layers.erase(ViewLayerType::PART_OF_SPEECH);
            layers.erase(ViewLayerType::META_MORPHEME);
            layers.erase(ViewLayerType::META_MORPHEME_MOVED);
            layers.erase(ViewLayerType::SEMANTICS);
            break;
        case ViewLayerType::ENGLISH_WORD:
            layers.emplace(ViewLayerType::ENGLISH_WORD, new EnglishWordLayer(layerValue));
            break;
        case ViewLayerType::PART_OF_SPEECH:
        case ViewLayerType::INFLECTIONAL_GROUP:
            layers.emplace(ViewLayerType::INFLECTIONAL_GROUP, new MorphologicalAnalysisLayer(layerValue));
            layers.emplace(ViewLayerType::PART_OF_SPEECH, new MorphologicalAnalysisLayer(layerValue));
            layers.erase(ViewLayerType::META_MORPHEME_MOVED);
            break;
        case ViewLayerType::META_MORPHEME:
            layers.emplace(ViewLayerType::META_MORPHEME, new MetaMorphemeLayer(layerValue));
            break;
        case ViewLayerType::META_MORPHEME_MOVED:
            layers.emplace(ViewLayerType::META_MORPHEME_MOVED, new MetaMorphemesMovedLayer(layerValue));
            break;
        case ViewLayerType::DEPENDENCY:
            layers.emplace(ViewLayerType::DEPENDENCY, new DependencyLayer(layerValue));
            break;
        case ViewLayerType::SEMANTICS:
            layers.emplace(ViewLayerType::SEMANTICS, new TurkishSemanticLayer(layerValue));
            break;
        case ViewLayerType::ENGLISH_SEMANTICS:
            layers.emplace(ViewLayerType::ENGLISH_SEMANTICS, new EnglishSemanticLayer(layerValue));
            break;
        case ViewLayerType::NER:
            layers.emplace(ViewLayerType::NER, new NERLayer(layerValue));
            break;
        case ViewLayerType::PROPBANK:
            layers.emplace(ViewLayerType::PROPBANK, new TurkishPropbankLayer(layerValue));
            break;
        case ViewLayerType::ENGLISH_PROPBANK:
            layers.emplace(ViewLayerType::ENGLISH_PROPBANK, new EnglishPropbankLayer(layerValue));
            break;
        case ViewLayerType::SHALLOW_PARSE:
            layers.emplace(ViewLayerType::SHALLOW_PARSE, new ShallowParseLayer(layerValue));
            break;
    }
}

void LayerInfo::setMorphologicalAnalysis(MorphologicalParse parse) {
    layers.emplace(ViewLayerType::INFLECTIONAL_GROUP, new MorphologicalAnalysisLayer(parse.to_string()));
    layers.emplace(ViewLayerType::PART_OF_SPEECH, new MorphologicalAnalysisLayer(parse.to_string()));
}

void LayerInfo::setMetaMorphemes(MetamorphicParse parse) {
    layers.emplace(ViewLayerType::META_MORPHEME, new MetaMorphemeLayer(parse.to_string()));
}

bool LayerInfo::layerExists(ViewLayerType viewLayerType) {
    return layers.find(viewLayerType) != layers.end();
}

ViewLayerType LayerInfo::checkLayer(ViewLayerType viewLayer) {
    switch (viewLayer){
        case ViewLayerType::TURKISH_WORD:
        case ViewLayerType::PERSIAN_WORD:
        case ViewLayerType::ENGLISH_SEMANTICS:
            if (layers.find(viewLayer) == layers.end()){
                return ViewLayerType::ENGLISH_WORD;
            }
        case ViewLayerType::PART_OF_SPEECH:
        case ViewLayerType::INFLECTIONAL_GROUP:
        case ViewLayerType::META_MORPHEME:
        case ViewLayerType::SEMANTICS:
        case ViewLayerType::NER:
        case ViewLayerType::PROPBANK:
        case ViewLayerType::SHALLOW_PARSE:
        case ViewLayerType::ENGLISH_PROPBANK:
            if (layers.find(viewLayer) == layers.end())
                return checkLayer(ViewLayerType::TURKISH_WORD);
            break;
        case ViewLayerType::META_MORPHEME_MOVED:
            if (layers.find(viewLayer) == layers.end())
                return checkLayer(ViewLayerType::META_MORPHEME);
            break;
    }
    return viewLayer;
}

int LayerInfo::getNumberOfWords() {
    if (layers.find(ViewLayerType::TURKISH_WORD) != layers.end()){
        return ((TurkishWordLayer*) (layers.find(ViewLayerType::TURKISH_WORD)->second))->size();
    } else {
        if (layers.find(ViewLayerType::PERSIAN_WORD) != layers.end()){
            return ((PersianWordLayer*) (layers.find(ViewLayerType::PERSIAN_WORD)->second))->size();
        }
    }
}

string LayerInfo::getMultiWordAt(ViewLayerType viewLayerType, int index, string layerName) {
    if (layers.find(viewLayerType) != layers.end()){
            MultiWordLayer<string>* multiWordLayer = (MultiWordLayer<string>*) (layers.find(viewLayerType)->second);
            if (index < multiWordLayer->size() && index >= 0){
                return multiWordLayer->getItemAt(index);
            } else {
                if (viewLayerType == ViewLayerType::SEMANTICS){
                    return multiWordLayer->getItemAt(multiWordLayer->size() - 1);
                }
            }
    }
}

string LayerInfo::getTurkishWordAt(int index) {
    return getMultiWordAt(ViewLayerType::TURKISH_WORD, index, "turkish");
}

int LayerInfo::getNumberOfMeanings() {
    if (layers.find(ViewLayerType::SEMANTICS) != layers.end()){
        return ((TurkishSemanticLayer*) (layers.find(ViewLayerType::SEMANTICS)->second))->size();
    } else {
        return 0;
    }
}

string LayerInfo::getSemanticAt(int index) {
    return getMultiWordAt(ViewLayerType::SEMANTICS, index, "semantics");
}

string LayerInfo::getShallowParseAt(int index) {
    return getMultiWordAt(ViewLayerType::SHALLOW_PARSE, index, "shallowParse");
}
