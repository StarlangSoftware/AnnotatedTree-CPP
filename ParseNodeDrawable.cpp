//
// Created by Olcay Taner YILDIZ on 2019-05-12.
//

#include "ParseNodeDrawable.h"

ParseNodeDrawable::ParseNodeDrawable(ParseNodeDrawable *parent, string line, bool isLeaf, int depth) {
    int parenthesisCount = 0;
    string childLine;
    this->depth = depth;
    this->parent = parent;
    if (parent != nullptr){
        this->childIndex = parent->children.size();
    }
    if (isLeaf){
        if (line.find("{") == string::npos){
            data = Symbol(line);
        } else {
            layers = new LayerInfo(line);
        }
    } else {
        int startPos = line.find(" ");
        data = Symbol(line.substr(1, startPos - 1));
        if (line.find_first_of(")") == line.find_last_of(")")){
            children.emplace_back(new ParseNodeDrawable(this, line.substr(startPos + 1, line.find(")") - startPos), true, depth + 1));
        } else {
            for (int i = startPos + 1; i < line.size(); i++){
                if (line[i] != ' ' || parenthesisCount > 0){
                    childLine += line[i];
                }
                if (line[i] == '('){
                    parenthesisCount++;
                } else {
                    if (line[i] == ')'){
                        parenthesisCount--;
                    }
                }
                if (parenthesisCount == 0 && !childLine.empty()){
                    children.emplace_back(new ParseNodeDrawable(this, Word::trim(childLine), false, depth + 1));
                    childLine = "";
                }
            }
        }
    }
}

ParseNodeDrawable::ParseNodeDrawable(Symbol data) : ParseNode(move(data)) {
}

ParseNodeDrawable::~ParseNodeDrawable(){
    if (layers != nullptr){
        delete layers;
    }
}

ParseNodeDrawable::ParseNodeDrawable(ParseNodeDrawable *parent, ParseNodeDrawable *child, string symbol) {
    this->depth = child->depth;
    child->updateDepths(this->depth + 1);
    this->parent = parent;
    this->childIndex = child->childIndex;
    this->parent->setChild(this->childIndex, this);
    this->children.emplace_back(child);
    child->childIndex = 0;
    child->parent = this;
    this->data = Symbol(move(symbol));
}

LayerInfo* ParseNodeDrawable::getLayerInfo() {
    return layers;
}

Symbol ParseNodeDrawable::getData() {
    if (layers == nullptr){
        return ParseNode::getData();
    } else {
        return Symbol(getLayerData(ViewLayerType::ENGLISH_WORD));
    }
}

void ParseNodeDrawable::clearLayers() {
    layers = new LayerInfo();
}

void ParseNodeDrawable::clearLayer(ViewLayerType layerType) {
    if (children.empty() && layerExists(layerType)){
        layers->removeLayer(layerType);
    }
    for (int i = 0; i < numberOfChildren(); i++){
        ((ParseNodeDrawable*) children.at(i))->clearLayer(layerType);
    }
}

void ParseNodeDrawable::clearData() {
    data = Symbol("");
}

void ParseNodeDrawable::setDataAndClearLayers(Symbol data) {
    ParseNode::setData(move(data));
    layers = nullptr;
}

void ParseNodeDrawable::setData(Symbol data) {
    if (layers == nullptr){
        ParseNode::setData(data);
    } else {
        layers->setLayerData(ViewLayerType::ENGLISH_WORD, data.getName());
    }
}

string ParseNodeDrawable::headWord(ViewLayerType viewLayerType) {
    if (!children.empty()){
        return ((ParseNodeDrawable*) headChild())->headWord(viewLayerType);
    } else {
        return getLayerData(viewLayerType);
    }
}

string ParseNodeDrawable::getLayerData() {
    if (!data.getName().empty())
        return data.getName();
    return layers->getLayerDescription();
}

string ParseNodeDrawable::getLayerData(ViewLayerType viewLayer) {
    if (viewLayer == ViewLayerType::WORD || layers == nullptr)
        return data.getName();
    return layers->getLayerData(viewLayer);
}

int ParseNodeDrawable::getDepth() {
    return depth;
}

int ParseNodeDrawable::structureAgreementCount(ParseNodeDrawable *parseNode) {
    if (children.size() > 1){
        int sum = 1;
        for (int i = 0; i < children.size(); i++){
            if (i < parseNode->numberOfChildren()){
                if (getChild(i)->getData().getName() != parseNode->getChild(i)->getData().getName()){
                    sum = 0;
                    break;
                }
            } else {
                sum = 0;
                break;
            }
        }
        for (int i = 0; i < children.size(); i++){
            if (i < parseNode->numberOfChildren() && getChild(i)->getData().getName() == parseNode->getChild(i)->getData().getName()){
                sum += ((ParseNodeDrawable*) getChild(i))->structureAgreementCount((ParseNodeDrawable*) parseNode->getChild(i));
            } else {
                for (int j = 0; j < parseNode->numberOfChildren(); j++){
                    if (getChild(i)->getData().getName() == parseNode->getChild(j)->getData().getName()){
                        sum += ((ParseNodeDrawable*) getChild(i))->structureAgreementCount((ParseNodeDrawable*) parseNode->getChild(j));
                        break;
                    }
                }
            }
        }
        return sum;
    } else {
        return 0;
    }
}

int ParseNodeDrawable::glossAgreementCount(ParseNodeDrawable* parseNode, ViewLayerType viewLayerType){
    if (children.empty()){
        if (parseNode->numberOfChildren() == 0){
            if (getLayerData(viewLayerType) == parseNode->getLayerData(viewLayerType)){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        int sum = 0;
        for (int i = 0; i < children.size(); i++){
            if (i < parseNode->numberOfChildren()){
                sum += ((ParseNodeDrawable*) getChild(i))->glossAgreementCount((ParseNodeDrawable*) parseNode->getChild(i), viewLayerType);
            }
        }
        return sum;
    }
}

void ParseNodeDrawable::updateDepths(int depth){
    this->depth = depth;
    for (ParseNode* aChildren:children){
        auto * aChild = (ParseNodeDrawable*) aChildren;
        aChild->updateDepths(depth + 1);
    }
}

int ParseNodeDrawable::maxDepth() {
    int depth = this->depth;
    for (ParseNode* aChildren : children) {
        auto* aChild = (ParseNodeDrawable*) aChildren;
        if (aChild->maxDepth() > depth)
            depth = aChild->maxDepth();
    }
    return depth;
}

string ParseNodeDrawable::ancestorString(){
    if (parent == nullptr){
        return data.getName();
    } else {
        if (layers == nullptr){
            return parent->ancestorString() + data.getName();
        } else {
            return parent->ancestorString() + layers->getLayerData(ViewLayerType::ENGLISH_WORD);
        }
    }
}

bool ParseNodeDrawable::layerExists(ViewLayerType viewLayerType){
    if (children.empty()){
        if (!getLayerData(viewLayerType).empty()){
            return true;
        }
    } else {
        for (ParseNode* aChild : children) {
            if (((ParseNodeDrawable*)aChild)->layerExists(viewLayerType)){
                return true;
            }
        }
    }
    return false;
}

bool ParseNodeDrawable::isDummyNode(){
    string data = getLayerData(ViewLayerType::ENGLISH_WORD);
    string parentData = ((ParseNodeDrawable*) parent)->getLayerData(ViewLayerType::ENGLISH_WORD);
    string targetData = getLayerData(ViewLayerType::TURKISH_WORD);
    if (!data.empty() && !parentData.empty()){
        if (!targetData.empty() && targetData.find('*') != string::npos){
            return true;
        }
        return data.find('*') != string::npos || (data == "0" && parentData == "-NONE-");
    } else {
        return false;
    }
}

bool ParseNodeDrawable::layerAll(ViewLayerType viewLayerType){
    if (children.empty()){
        if (getLayerData(viewLayerType).empty() && !isDummyNode()){
            return false;
        }
    } else {
        for (ParseNode* aChild : children) {
            if (!((ParseNodeDrawable*)aChild)->layerAll(viewLayerType)){
                return false;
            }
        }
    }
    return true;
}

string ParseNodeDrawable::toTurkishSentence() {
    if (children.empty()){
        if (!getLayerData(ViewLayerType::TURKISH_WORD).empty() && !isDummyNode()){
            return " " + getLayerData(ViewLayerType::TURKISH_WORD);
        } else {
            return " ";
        }
    } else {
        string st;
        for (ParseNode* aChild : children) {
            st += aChild->toSentence();
        }
        return st;
    }
}

void ParseNodeDrawable::checkGazetteer(Gazetteer gazetteer, string word){
    if (gazetteer.contains(word) && getParent()->getData().getName() == "NNP"){
        getLayerInfo()->setLayerData(ViewLayerType::NER, gazetteer.getName());
    }
    if (word.find("'") != string::npos && gazetteer.contains(word.substr(0, word.find("'"))) && getParent()->getData().getName() == "NNP"){
        getLayerInfo()->setLayerData(ViewLayerType::NER, gazetteer.getName());
    }
}

string ParseNodeDrawable::to_string(){
    if (children.size() < 2){
        if (children.size() < 1){
            return getLayerData();
        } else {
            return "(" + data.getName() + " " + children.at(0)->to_string() + ")";
        }
    } else {
        string st = "(" + data.getName();
        for (ParseNode* aChild : children) {
            st = st + " " + aChild->to_string();
        }
        return st + ") ";
    }
}