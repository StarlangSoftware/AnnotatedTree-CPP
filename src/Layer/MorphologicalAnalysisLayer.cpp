//
// Created by Olcay Taner YILDIZ on 2019-05-09.
//

#include "MorphologicalAnalysisLayer.h"

MorphologicalAnalysisLayer::MorphologicalAnalysisLayer(const string& layerValue) {
    layerName = "morphologicalAnalysis";
    setLayerValue(layerValue);
}

void MorphologicalAnalysisLayer::setLayerValue(const string& layerValue) {
    this->layerValue = layerValue;
    if (!layerValue.empty()){
        vector<string> splitWords = Word::split(layerValue);
        for (const string &word:splitWords){
            items.emplace_back(MorphologicalParse(word));
        }
    }
}

void MorphologicalAnalysisLayer::setLayerValue(const MorphologicalParse& parse) {
    layerValue = parse.getTransitionList();
    items.emplace_back(parse);
}

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

