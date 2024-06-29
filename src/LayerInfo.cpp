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

/**
 * Constructs the layer information from the given string. Layers are represented as
 * {layername1=layervalue1}{layername2=layervalue2}...{layernamek=layervaluek} where layer name is one of the
 * following: turkish, persian, english, morphologicalAnalysis, metaMorphemes, metaMorphemesMoved, dependency,
 * semantics, namedEntity, propBank, englishPropbank, englishSemantics, shallowParse. Splits the string w.r.t.
 * parentheses and constructs layer objects and put them layers map accordingly.
 * @param info Line consisting of layer info.
 */
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

/**
 * Changes the given layer info with the given string layer value. For all layers new layer object is created and
 * replaces the original object. For turkish layer, it also destroys inflectional_group, part_of_speech,
 * meta_morpheme, meta_morpheme_moved and semantics layers. For persian layer, it also destroys the semantics layer.
 * @param viewLayer Layer name.
 * @param layerValue New layer value.
 */
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

/**
 * Updates the inflectional_group and part_of_speech layers according to the given parse.
 * @param parse New parse to update layers.
 */
void LayerInfo::setMorphologicalAnalysis(const MorphologicalParse& parse) {
    layers.emplace(ViewLayerType::INFLECTIONAL_GROUP, new MorphologicalAnalysisLayer(parse.to_string()));
    layers.emplace(ViewLayerType::PART_OF_SPEECH, new MorphologicalAnalysisLayer(parse.to_string()));
}

/**
 * Updates the metamorpheme layer according to the given parse.
 * @param parse NEw parse to update layer.
 */
void LayerInfo::setMetaMorphemes(const MetamorphicParse& parse) {
    layers.emplace(ViewLayerType::META_MORPHEME, new MetaMorphemeLayer(parse.to_string()));
}

/**
 * Checks if the given layer exists.
 * @param viewLayerType Layer name
 * @return True if the layer exists, false otherwise.
 */
bool LayerInfo::layerExists(ViewLayerType viewLayerType) const{
    return layers.contains(viewLayerType);
}

/**
 * Two level layer check method. For turkish, persian and english_semantics layers, if the layer does not exist,
 * returns english layer. For part_of_speech, inflectional_group, meta_morpheme, semantics, propbank, shallow_parse,
 * english_propbank layers, if the layer does not exist, it checks turkish layer. For meta_morpheme_moved, if the
 * layer does not exist, it checks meta_morpheme layer.
 * @param viewLayer Layer to be checked.
 * @return Returns the original layer if the layer exists. For turkish, persian and english_semantics layers, if the
 * layer  does not exist, returns english layer. For part_of_speech, inflectional_group, meta_morpheme, semantics,
 * propbank,  shallow_parse, english_propbank layers, if the layer does not exist, it checks turkish layer
 * recursively. For meta_morpheme_moved, if the layer does not exist, it checks meta_morpheme layer recursively.
 */
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

/**
 * Returns number of words in the Turkish or Persian layer, whichever exists.
 * @return Number of words in the Turkish or Persian layer, whichever exists.
 */
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

/**
 * Returns the layer value at the given index.
 * @param viewLayerType Layer for which the value at the given word index will be returned.
 * @param index Word Position of the layer value.
 * @param layerName Name of the layer.
 * @throws LayerNotExistsException If the layer does not exist, it throws LayerNotExistsException. If the layer is
 * not a MultiWordLayer, it throws LayerNotExistsException exception.
 * @throws WordNotExistsException If the index is out of bounds, it throws WordNotExistsException.
 * @return Layer info at word position index for a multiword layer.
 */
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

/**
 * Layers may contain multiple Turkish words. This method returns the Turkish word at position index.
 * @param index Position of the Turkish word.
 * @throws LayerNotExistsException If the layer does not exist, it throws LayerNotExistsException.
 * @throws WordNotExistsException If the index is out of bounds, it throws WordNotExistsException.
 * @return The Turkish word at position index.
 */
string LayerInfo::getTurkishWordAt(int index) const{
    return getMultiWordAt(ViewLayerType::TURKISH_WORD, index, "turkish");
}

/**
 * Returns number of meanings in the Turkish layer.
 * @return Number of meanings in the Turkish layer.
 */
int LayerInfo::getNumberOfMeanings() const{
    if (layers.contains(ViewLayerType::SEMANTICS)){
        return ((TurkishSemanticLayer*) (layers.find(ViewLayerType::SEMANTICS)->second))->size();
    } else {
        return 0;
    }
}

/**
 * Layers may contain multiple semantic information corresponding to multiple Turkish words. This method returns
 * the sense id at position index.
 * @param index Position of the Turkish word.
 * @throws LayerNotExistsException If the layer does not exist, it throws LayerNotExistsException.
 * @throws WordNotExistsException If the index is out of bounds, it throws WordNotExistsException.
 * @return The Turkish sense id at position index.
 */
string LayerInfo::getSemanticAt(int index) const{
    return getMultiWordAt(ViewLayerType::SEMANTICS, index, "semantics");
}

/**
 * Layers may contain multiple shallow parse information corresponding to multiple Turkish words. This method
 * returns the shallow parse tag at position index.
 * @param index Position of the Turkish word.
 * @throws LayerNotExistsException If the layer does not exist, it throws LayerNotExistsException.
 * @throws WordNotExistsException If the index is out of bounds, it throws WordNotExistsException.
 * @return The shallow parse tag at position index.
 */
string LayerInfo::getShallowParseAt(int index) const{
    return getMultiWordAt(ViewLayerType::SHALLOW_PARSE, index, "shallowParse");
}

/**
 * Returns the Turkish PropBank argument info.
 * @return Turkish PropBank argument info.
 */
Argument LayerInfo::getArgument() const{
    if (layers.contains(ViewLayerType::PROPBANK)){
        TurkishPropbankLayer* argumentLayer = (TurkishPropbankLayer*) layers.find(ViewLayerType::PROPBANK)->second;
        return argumentLayer->getArgument();
    }
}

/**
 * A word may have multiple English propbank info. This method returns the English PropBank argument info at
 * position index.
 * @return English PropBank argument info at position index.
 */
Argument LayerInfo::getArgumentAt(int index) const{
    if (layers.contains(ViewLayerType::ENGLISH_PROPBANK)){
        SingleWordMultiItemLayer<Argument>* multiArgumentLayer = (SingleWordMultiItemLayer<Argument>*) layers.find(ViewLayerType::ENGLISH_PROPBANK)->second;
        return multiArgumentLayer->getItemAt(index);
    }
}

/**
 * Layers may contain multiple morphological parse information corresponding to multiple Turkish words. This method
 * returns the morphological parse at position index.
 * @param index Position of the Turkish word.
 * @return The morphological parse at position index.
 */
MorphologicalParse LayerInfo::getMorphologicalParseAt(int index) const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        MultiWordLayer<MorphologicalParse>* multiWordLayer = (MultiWordLayer<MorphologicalParse>*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second;
        if (index < multiWordLayer->size() && index >= 0){
            return multiWordLayer->getItemAt(index);
        }
    }
}

/**
 * Layers may contain multiple metamorphic parse information corresponding to multiple Turkish words. This method
 * returns the metamorphic parse at position index.
 * @param index Position of the Turkish word.
 * @return The metamorphic parse at position index.
 */
MetamorphicParse LayerInfo::getMetamorphicParseAt(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MultiWordLayer<MetamorphicParse>* multiWordLayer = (MultiWordLayer<MetamorphicParse>*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < multiWordLayer->size() && index >= 0){
            return multiWordLayer->getItemAt(index);
        }
    }
}

/**
 * Layers may contain multiple metamorphemes corresponding to one or multiple Turkish words. This method
 * returns the metamorpheme at position index.
 * @param index Position of the metamorpheme.
 * @return The metamorpheme at position index.
 */
string LayerInfo::getMetaMorphemeAtIndex(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MetaMorphemeLayer* metaMorphemeLayer = (MetaMorphemeLayer*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < metaMorphemeLayer->getLayerSize(ViewLayerType::META_MORPHEME) && index >= 0){
            return metaMorphemeLayer->getLayerInfoAt(ViewLayerType::META_MORPHEME, index);
        }
    }
    return "";
}

/**
 * Layers may contain multiple metamorphemes corresponding to one or multiple Turkish words. This method
 * returns all metamorphemes from position index.
 * @param index Start position of the metamorpheme.
 * @return All metamorphemes from position index.
 */
string LayerInfo::getMetaMorphemeFromIndex(int index) const{
    if (layers.contains(ViewLayerType::META_MORPHEME)){
        MetaMorphemeLayer* metaMorphemeLayer = (MetaMorphemeLayer*) layers.find(ViewLayerType::META_MORPHEME)->second;
        if (index < metaMorphemeLayer->getLayerSize(ViewLayerType::META_MORPHEME) && index >= 0){
            return metaMorphemeLayer->getLayerInfoFrom(index);
        }
    }
    return "";
}

/**
 * For layers with multiple item information, this method returns total items in that layer.
 * @param viewLayer Layer name
 * @return Total items in the given layer.
 */
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

/**
 * For layers with multiple item information, this method returns the item at position index.
 * @param viewLayer Layer name
 * @param index Position of the item.
 * @return The item at position index.
 */
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

/**
 * Returns the string form of all layer information except part_of_speech layer.
 * @return The string form of all layer information except part_of_speech layer.
 */
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

/**
 * Returns the layer info for the given layer.
 * @param viewLayer Layer name.
 * @return Layer info for the given layer.
 */
string LayerInfo::getLayerData(ViewLayerType viewLayer) const{
    if (layers.contains(viewLayer)){
        return layers.find(viewLayer)->second->getLayerValue();
    } else {
        return "";
    }
}

/**
 * Returns the layer info for the given layer, if that layer exists. Otherwise, it returns the fallback layer info
 * determined by the checkLayer.
 * @param viewLayer Layer name
 * @return Layer info for the given layer if it exists. Otherwise, it returns the fallback layer info determined by
 * the checkLayer.
 */
string LayerInfo::getRobustLayerData(ViewLayerType viewLayer) const{
    viewLayer = checkLayer(viewLayer);
    return getLayerData(viewLayer);
}

/**
 * Initializes the metamorphemesmoved layer with metamorpheme layer except the root word.
 * @throws LayerNotExistsException If the layer does not exist, it throws LayerNotExistsException.
 * @throws WordNotExistsException If the root word does not exist, it throws WordNotExistsException.
 */
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

/**
 * Removes the given layer from hash map.
 * @param layerType Layer to be removed.
 */
void LayerInfo::removeLayer(ViewLayerType layerType) {
    layers.erase(layerType);
}

/**
 * Removes metamorpheme and metamorphemesmoved layers.
 */
void LayerInfo::metaMorphemeClear() {
    layers.erase(ViewLayerType::META_MORPHEME);
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

/**
 * Removes English layer.
 */
void LayerInfo::englishClear() {
    layers.erase(ViewLayerType::ENGLISH_WORD);
}

/**
 * Removes the dependency layer.
 */
void LayerInfo::dependencyClear() {
    layers.erase(ViewLayerType::DEPENDENCY);
}

/**
 * Removed metamorphemesmoved layer.
 */
void LayerInfo::metaMorphemesMovedClear() {
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

/**
 * Removes the Turkish semantic layer.
 */
void LayerInfo::semanticClear() {
    layers.erase(ViewLayerType::SEMANTICS);
}

/**
 * Removes the English semantic layer.
 */
void LayerInfo::englishSemanticClear() {
    layers.erase(ViewLayerType::ENGLISH_SEMANTICS);
}

/**
 * Removes the morphological analysis, part of speech, metamorpheme, and metamorphemesmoved layers.
 */
void LayerInfo::morphologicalAnalysisClear() {
    layers.erase(ViewLayerType::INFLECTIONAL_GROUP);
    layers.erase(ViewLayerType::PART_OF_SPEECH);
    layers.erase(ViewLayerType::META_MORPHEME);
    layers.erase(ViewLayerType::META_MORPHEME_MOVED);
}

/**
 * Removes the metamorpheme at position index.
 * @param index Position of the metamorpheme to be removed.
 * @return Metamorphemes concatenated as a string after the removed metamorpheme.
 */
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

/**
 * Checks if the last inflectional group contains VERB tag.
 * @return True if the last inflectional group contains VERB tag, false otherwise.
 */
bool LayerInfo::isVerbal() const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        return ((MorphologicalAnalysisLayer*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second)->isVerbal();
    } else {
        return false;
    }
}

/**
 * Checks if the last verbal inflectional group contains ZERO tag.
 * @return True if the last verbal inflectional group contains ZERO tag, false otherwise.
 */
bool LayerInfo::isNominal() const{
    if (layers.contains(ViewLayerType::INFLECTIONAL_GROUP)){
        return ((MorphologicalAnalysisLayer*) layers.find(ViewLayerType::INFLECTIONAL_GROUP)->second)->isNominal();
    } else {
        return false;
    }
}

/**
 * Converts layer info of the word at position wordIndex to an AnnotatedWord. Layers are converted to their
 * counterparts in the AnnotatedWord.
 * @param wordIndex Index of the word to be converted.
 * @return Converted annotatedWord
 */
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
