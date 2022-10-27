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
#include "Dictionary/Word.h"

LayerInfo::LayerInfo(const string& info) {
    vector<string> splitLayers = Word::split(info, "[{}]");
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

void LayerInfo::setLayerData(ViewLayerType viewLayer, const string& layerValue) {
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
        default:
            break;
    }
}

void LayerInfo::setMorphologicalAnalysis(const MorphologicalParse& parse) {
    layers.emplace(ViewLayerType::INFLECTIONAL_GROUP, new MorphologicalAnalysisLayer(parse.to_string()));
    layers.emplace(ViewLayerType::PART_OF_SPEECH, new MorphologicalAnalysisLayer(parse.to_string()));
}

void LayerInfo::setMetaMorphemes(const MetamorphicParse& parse) {
    layers.emplace(ViewLayerType::META_MORPHEME, new MetaMorphemeLayer(parse.to_string()));
}

bool LayerInfo::layerExists(ViewLayerType viewLayerType) const{
    return layers.contains(viewLayerType);
}

ViewLayerType LayerInfo::checkLayer(ViewLayerType viewLayer) const{
    switch (viewLayer){
        case ViewLayerType::TURKISH_WORD:
        case ViewLayerType::PERSIAN_WORD:
        case ViewLayerType::ENGLISH_SEMANTICS:
            if (!layers.contains(viewLayer)){
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
            if (!layers.contains(viewLayer))
                return checkLayer(ViewLayerType::TURKISH_WORD);
            break;
        case ViewLayerType::META_MORPHEME_MOVED:
            if (!layers.contains(viewLayer))
                return checkLayer(ViewLayerType::META_MORPHEME);
            break;
        default:
            break;
    }
    return viewLayer;
}

int LayerInfo::getNumberOfWords() const{
    if (layers.contains(ViewLayerType::TURKISH_WORD)){
        return ((TurkishWordLayer*) (layers.find(ViewLayerType::TURKISH_WORD)->second))->size();
    } else {
        if (layers.contains(ViewLayerType::PERSIAN_WORD)){
            return ((PersianWordLayer*) (layers.find(ViewLayerType::PERSIAN_WORD)->second))->size();
        }
    }
    return 0;
}

string LayerInfo::getMultiWordAt(ViewLayerType viewLayerType, int index, const string& layerName) const{
    if (layers.contains(viewLayerType)){
            MultiWordLayer<string>* multiWordLayer = (MultiWordLayer<string>*) (layers.find(viewLayerType)->second);
            if (index < multiWordLayer->size() && index >= 0){
                return multiWordLayer->getItemAt(index);
            } else {
                if (viewLayerType == ViewLayerType::SEMANTICS){
                    return multiWordLayer->getItemAt(multiWordLayer->size() - 1);
                }
            }
    }
    return "";
}

string LayerInfo::getTurkishWordAt(int index) const{
    return getMultiWordAt(ViewLayerType::TURKISH_WORD, index, "turkish");
}

int LayerInfo::getNumberOfMeanings() const{
    if (layers.contains(ViewLayerType::SEMANTICS)){
        return ((TurkishSemanticLayer*) (layers.find(ViewLayerType::SEMANTICS)->second))->size();
    } else {
        return 0;
    }
}

string LayerInfo::getSemanticAt(int index) const{
    return getMultiWordAt(ViewLayerType::SEMANTICS, index, "semantics");
}

string LayerInfo::getShallowParseAt(int index) const{
    return getMultiWordAt(ViewLayerType::SHALLOW_PARSE, index, "shallowParse");
}

Argument LayerInfo::getArgument() const{
    if (layers.contains(ViewLayerType::PROPBANK)){
        TurkishPropbankLayer* argumentLayer = (TurkishPropbankLayer*) layers.find(ViewLayerType::PROPBANK)->second;
        return argumentLayer->getArgument();
    }
}

Argument LayerInfo::getArgumentAt(int index) const{
    if (layers.contains(ViewLayerType::ENGLISH_PROPBANK)){
        SingleWordMultiItemLayer<Argument>* multiArgumentLayer = (SingleWordMultiItemLayer<Argument>*) layers.find(ViewLayerType::ENGLISH_PROPBANK)->second;
        return multiArgumentLayer->getItemAt(index);
    }
}

MorphologicalParse LayerInfo::getMorphologicalParseAt(int index) const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        MultiWordLayer<MorphologicalParse>* multiWordLayer = (MultiWordLayer<MorphologicalParse>*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second;
        if (index < multiWordLayer->size() && index >= 0){
            return multiWordLayer->getItemAt(index);
        }
    }
}

MetamorphicParse LayerInfo::getMetamorphicParseAt(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MultiWordLayer<MetamorphicParse>* multiWordLayer = (MultiWordLayer<MetamorphicParse>*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < multiWordLayer->size() && index >= 0){
            return multiWordLayer->getItemAt(index);
        }
    }
}

string LayerInfo::getMetaMorphemeAtIndex(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MetaMorphemeLayer* metaMorphemeLayer = (MetaMorphemeLayer*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < metaMorphemeLayer->getLayerSize(ViewLayerType::META_MORPHEME) && index >= 0){
            return metaMorphemeLayer->getLayerInfoAt(ViewLayerType::META_MORPHEME, index);
        }
    }
    return "";
}

string LayerInfo::getMetaMorphemeFromIndex(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MetaMorphemeLayer* metaMorphemeLayer = (MetaMorphemeLayer*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < metaMorphemeLayer->getLayerSize(ViewLayerType::META_MORPHEME) && index >= 0){
            return metaMorphemeLayer->getLayerInfoFrom(index);
        }
    }
    return "";
}

int LayerInfo::getLayerSize(ViewLayerType viewLayer) const{
    switch (viewLayer){
        case ViewLayerType::META_MORPHEME_MOVED:
        case ViewLayerType::META_MORPHEME:
            return ((MultiWordMultiItemLayer<MetamorphicParse>*) layers.find(viewLayer)->second)->getLayerSize(viewLayer);
        case ViewLayerType::PART_OF_SPEECH:
        case ViewLayerType::INFLECTIONAL_GROUP:
            return ((MultiWordMultiItemLayer<MorphologicalParse>*) layers.find(viewLayer)->second)->getLayerSize(viewLayer);
        case ViewLayerType::ENGLISH_PROPBANK:
            return ((SingleWordMultiItemLayer<Argument>*) layers.find(viewLayer)->second)->getLayerSize();
        default:
            return 0;
    }
}

string LayerInfo::getLayerInfoAt(ViewLayerType viewLayer, int index) const{
    switch (viewLayer){
        case ViewLayerType::META_MORPHEME_MOVED:
            return ((MultiWordMultiItemLayer<MetamorphicParse>*) layers.find(viewLayer)->second)->getLayerInfoAt(viewLayer, index);
        case ViewLayerType::PART_OF_SPEECH:
        case ViewLayerType::INFLECTIONAL_GROUP:
            return ((MultiWordMultiItemLayer<MorphologicalParse>*) layers.find(viewLayer)->second)->getLayerInfoAt(viewLayer, index);
        case ViewLayerType::META_MORPHEME:
            return getMetaMorphemeAtIndex(index);
        case ViewLayerType::ENGLISH_PROPBANK:
            return getArgumentAt(index).getArgumentType();
        default:
            return "";
    }
}

string LayerInfo::getLayerDescription(){
    string result;
    map<ViewLayerType, WordLayer*>::iterator layerIterator;
    for (layerIterator = layers.begin(); layerIterator != layers.end(); layerIterator++){
        if (layerIterator->first != ViewLayerType::PART_OF_SPEECH){
            result += layerIterator->second->getLayerDescription();
        }
    }
    return result;
}

string LayerInfo::getLayerData(ViewLayerType viewLayer) const{
    if (layers.contains(viewLayer)){
        return layers.find(viewLayer)->second->getLayerValue();
    } else {
        return "";
    }
}

string LayerInfo::getRobustLayerData(ViewLayerType viewLayer) const{
    viewLayer = checkLayer(viewLayer);
    return getLayerData(viewLayer);
}

void LayerInfo::updateMetaMorphemesMoved() {
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MetaMorphemeLayer* metaMorphemeLayer = (MetaMorphemeLayer*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (metaMorphemeLayer->size() > 0){
            string result = metaMorphemeLayer->getItemAt(0).to_string();
            for (int i = 1; i < metaMorphemeLayer->size(); i++){
                result += " " + metaMorphemeLayer->getItemAt(i).to_string();
            }
            layers.insert_or_assign(ViewLayerType::META_MORPHEME_MOVED, new MetaMorphemesMovedLayer(result));
        }
    }
}

void LayerInfo::removeLayer(ViewLayerType layerType) {
    layers.erase(layerType);
}

void LayerInfo::metaMorphemeClear() {
    layers.erase(ViewLayerType::META_MORPHEME);
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

void LayerInfo::englishClear() {
    layers.erase(ViewLayerType::ENGLISH_WORD);
}

void LayerInfo::dependencyClear() {
    layers.erase(ViewLayerType::DEPENDENCY);
}

void LayerInfo::metaMorphemesMovedClear() {
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

void LayerInfo::semanticClear() {
    layers.erase(ViewLayerType::SEMANTICS);
}

void LayerInfo::englishSemanticClear() {
    layers.erase(ViewLayerType::ENGLISH_SEMANTICS);
}

void LayerInfo::morphologicalAnalysisClear() {
    layers.erase(ViewLayerType::INFLECTIONAL_GROUP);
    layers.erase(ViewLayerType::PART_OF_SPEECH);
    layers.erase(ViewLayerType::META_MORPHEME);
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

MetamorphicParse LayerInfo::metaMorphemeRemove(int index) {
    MetamorphicParse removedParse;
    if (layers.contains(ViewLayerType::META_MORPHEME)) {
        MetaMorphemeLayer *metaMorphemeLayer = (MetaMorphemeLayer *) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index >= 0 && index < metaMorphemeLayer->getLayerSize(ViewLayerType::META_MORPHEME)) {
            removedParse = metaMorphemeLayer->metaMorphemeRemoveFromIndex(index);
            updateMetaMorphemesMoved();
        }
    }
    return removedParse;
}

bool LayerInfo::isVerbal() const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        return ((MorphologicalAnalysisLayer*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second)->isVerbal();
    } else {
        return false;
    }
}

bool LayerInfo::isNominal() const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        return ((MorphologicalAnalysisLayer*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second)->isNominal();
    } else {
        return false;
    }
}

AnnotatedWord *LayerInfo::toAnnotatedWord(int wordIndex) const{
    auto* annotatedWord = new AnnotatedWord(getTurkishWordAt(wordIndex));
    if (layerExists(ViewLayerType::INFLECTIONAL_GROUP)){
        annotatedWord->setParse(getMorphologicalParseAt(wordIndex).to_string());
    }
    if (layerExists(ViewLayerType::META_MORPHEME)){
        annotatedWord->setMetamorphicParse(getMetamorphicParseAt(wordIndex).to_string());
    }
    if (layerExists(ViewLayerType::SEMANTICS)){
        annotatedWord->setSemantic(getSemanticAt(wordIndex));
    }
    if (layerExists(ViewLayerType::NER)){
        annotatedWord->setNamedEntityType(getLayerData(ViewLayerType::NER));
    }
    if (layerExists(ViewLayerType::PROPBANK)){
        annotatedWord->setArgument(getArgument().to_string());
    }
    if (layerExists(ViewLayerType::SHALLOW_PARSE)){
        annotatedWord->setShallowParse(getShallowParseAt(wordIndex));
    }
    return annotatedWord;
}

LayerInfo::~LayerInfo() {
    map<ViewLayerType, WordLayer*>::iterator iterator;
    for (iterator = layers.begin(); iterator != layers.end(); iterator++){
        delete iterator->second;
    }
}
