//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MorphologicalAnalysisLayer.h"

/**
 * Constructor for the morphological analysis layer. Sets the morphological parse information for multiple words in
 * the node.
 * @param layerValue Layer value for the morphological parse information. Consists of morphological parse information
 *                   of multiple words separated via space character.
 */
MorphologicalAnalysisLayer::MorphologicalAnalysisLayer(const string& layerValue) {
    layerName = "morphologicalAnalysis";
    setLayerValue(layerValue);
}

/**
 * Sets the layer value to the string form of the given morphological parse.
 * @param layerValue New morphological parse.
 */
void MorphologicalAnalysisLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MorphologicalParse(word));
        }
    }
}

/**
 * Sets the layer value to the string form of the given morphological parse.
 * @param parse New morphological parse.
 */
void MorphologicalAnalysisLayer::setLayerValue(const MorphologicalParse& parse) {
    layerValue = parse.getTransitionList();
    items.emplace_back(parse);
}

/**
 * Returns the total number of morphological tags (for PART_OF_SPEECH) or inflectional groups
 * (for INFLECTIONAL_GROUP) in the words in the node.
 * @param viewLayer Layer type.
 * @return Total number of morphological tags (for PART_OF_SPEECH) or inflectional groups (for INFLECTIONAL_GROUP)
 * in the words in the node.
 */
int MorphologicalAnalysisLayer::getLayerSize(ViewLayerType viewLayer) const{
    int size;
    switch (viewLayer){
        case ViewLayerType::PART_OF_SPEECH:
            size = 0;
            for (const MorphologicalParse& parse:items){
                size += parse.tagSize();
            }
            return size;
        case ViewLayerType::INFLECTIONAL_GROUP:
            size = 0;
            for (const MorphologicalParse& parse:items){
                size += parse.size();
            }
            return size;
        default:
            return 0;
    }
}

/**
 * Returns the morphological tag (for PART_OF_SPEECH) or inflectional group (for INFLECTIONAL_GROUP) at position
 * index.
 * @param viewLayer Layer type.
 * @param index Position of the morphological tag (for PART_OF_SPEECH) or inflectional group (for INFLECTIONAL_GROUP)
 * @return The morphological tag (for PART_OF_SPEECH) or inflectional group (for INFLECTIONAL_GROUP)
 */
string MorphologicalAnalysisLayer::getLayerInfoAt(ViewLayerType viewLayer, int index) const{
    int size;
    switch (viewLayer){
        case ViewLayerType::PART_OF_SPEECH:
            size = 0;
            for (const MorphologicalParse& parse:items){
                if (index < size + parse.tagSize()){
                    return parse.getTag(index - size);
                }
                size += parse.tagSize();
            }
            return "";
        case ViewLayerType::INFLECTIONAL_GROUP:
            size = 0;
            for (const MorphologicalParse& parse:items){
                if (index < size + parse.size()){
                    return parse.getInflectionalGroupString(index - size);
                }
                size += parse.size();
            }
            return "";
    }
    return "";
}

/**
 * Checks if the last inflectional group contains VERB tag.
 * @return True if the last inflectional group contains VERB tag, false otherwise.
 */
bool MorphologicalAnalysisLayer::isVerbal() const{
    string dbLabel = "^DB+";
    string needle = "VERB+";
    string haystack;
    if (layerValue.find(dbLabel) != string::npos)
        haystack = layerValue.substr(layerValue.find_last_of(dbLabel) + 4);
    else
        haystack = layerValue;
    return haystack.find(needle) != string::npos;
}

/**
 * Checks if the last verbal inflectional group contains ZERO tag.
 * @return True if the last verbal inflectional group contains ZERO tag, false otherwise.
 */
bool MorphologicalAnalysisLayer::isNominal() const{
    string dbLabel = "^DB+VERB+";
    string needle = "ZERO+";
    string haystack;
    if (layerValue.find(dbLabel) != string::npos)
        haystack = layerValue.substr(layerValue.find_last_of(dbLabel) + 9);
    else
        haystack = layerValue;
    return haystack.find(needle) != string::npos;
}

