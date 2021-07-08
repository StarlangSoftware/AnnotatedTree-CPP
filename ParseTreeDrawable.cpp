//
// Created by olcay on 2019-05-13.
//

#include <istream>
#include <fstream>
#include "ParseTreeDrawable.h"
#include "ParseNodeDrawable.h"
#include "Processor/NodeDrawableCollector.h"
#include "Processor/Condition/IsTurkishLeafNode.h"

ParseTreeDrawable::ParseTreeDrawable(const string& path, const string& rawFileName) : ParseTreeDrawable(FileDescription(path, rawFileName)){
}

ParseTreeDrawable::ParseTreeDrawable(const string &path, const string &extension, int index) : ParseTreeDrawable(FileDescription(path, extension, index)){
}

ParseTreeDrawable::ParseTreeDrawable(const string& path, FileDescription fileDescription) : ParseTreeDrawable(path, fileDescription.getExtension(), fileDescription.getIndex()) {
}

ParseTreeDrawable::ParseTreeDrawable(FileDescription fileDescription) {
    this->fileDescription = move(fileDescription);
    readFromFile(fileDescription.getPath());
}

void ParseTreeDrawable::setFileDescription(const FileDescription& fileDescription) {
    this->fileDescription = fileDescription;
}

FileDescription ParseTreeDrawable::getFileDescription() {
    return fileDescription;
}

void ParseTreeDrawable::copyInfo(const ParseTreeDrawable& parseTree) {
    this->fileDescription = parseTree.fileDescription;
}

void ParseTreeDrawable::reload() {
    readFromFile(fileDescription.getPath());
}

void ParseTreeDrawable::readFromFile(const string& currentPath) {
    ifstream inputFile;
    inputFile.open(currentPath, ios::in);
    string line;
    getline(inputFile, line);
    if (line.find('(') != string::npos && line.find(')') != string::npos){
        line = Word::trim(line.substr(line.find('(') + 1, line.find_last_of(')') - line.find('(')));
        root = new ParseNodeDrawable(nullptr, line, false, 0);
    }
    inputFile.close();
}

ParseTreeDrawable::ParseTreeDrawable(istream &inputFile) {
    string line;
    getline(inputFile, line);
    if (line.find('(') != string::npos && line.find(')') != string::npos){
        line = Word::trim(line.substr(line.find('(') + 1, line.find_last_of(')') - line.find('(')));
        root = new ParseNodeDrawable(nullptr, line, false, 0);
    }
}

ParseTreeDrawable::ParseTreeDrawable(string line) {
    line = Word::replaceAll(line, "\n", "");
    line = Word::replaceAll(line, "\t", "");
    if (line.find('(') != string::npos && line.find(')') != string::npos){
        line = Word::trim(line.substr(line.find('(') + 1, line.find_last_of(')') - line.find('(')));
        root = new ParseNodeDrawable(nullptr, line, false, 0);
    }
}

void ParseTreeDrawable::setName(string name) {
    this->name = move(name);
}

string ParseTreeDrawable::getName(){
    return name;
}

void ParseTreeDrawable::nextTree(int count) {
    fileDescription.addToIndex(count);
    reload();
}

void ParseTreeDrawable::previousTree(int count) {
    fileDescription.addToIndex(-count);
    reload();
}

void ParseTreeDrawable::save() {
    ofstream outputFile;
    outputFile.open(name, ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

void ParseTreeDrawable::saveWithPath(const string& newPath) {
    ofstream outputFile;
    outputFile.open(newPath, ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

int ParseTreeDrawable::glossAgreementCount(ParseTree parseTree, ViewLayerType viewLayerType) {
    return ((ParseNodeDrawable*)root)->glossAgreementCount((ParseNodeDrawable*) parseTree.getRoot(), viewLayerType);
}

int ParseTreeDrawable::structureAgreementCount(ParseTree parseTree) {
    return ((ParseNodeDrawable*)root)->structureAgreementCount((ParseNodeDrawable*)parseTree.getRoot());
}

int ParseTreeDrawable::maxDepth() {
    return ((ParseNodeDrawable*) root)->maxDepth();
}

bool ParseTreeDrawable::layerExists(ViewLayerType viewLayerType){
    return ((ParseNodeDrawable*)(root))->layerExists(viewLayerType);
}

bool ParseTreeDrawable::layerAll(ViewLayerType viewLayerType){
    return ((ParseNodeDrawable*)(root))->layerAll(viewLayerType);
}

void ParseTreeDrawable::clearLayer(ViewLayerType layerType) {
    if (root != nullptr){
        ((ParseNodeDrawable*)root)->clearLayer(layerType);
    }
}

vector<ParseNodeDrawable*> ParseTreeDrawable::satisfy(ParseTreeSearchable tree){
    return ((ParseNodeDrawable*)root)->satisfy(tree);
}

AnnotatedSentence* ParseTreeDrawable::generateAnnotatedSentence() {
    auto* sentence = new AnnotatedSentence();
    NodeDrawableCollector nodeDrawableCollector = NodeDrawableCollector((ParseNodeDrawable*)root, new IsTurkishLeafNode());
    vector<ParseNodeDrawable*> leafList = nodeDrawableCollector.collect();
    for (ParseNodeDrawable* parseNode : leafList){
        LayerInfo* layers = parseNode->getLayerInfo();
        for (int i = 0; i < layers->getNumberOfWords(); i++){
            sentence->addWord(layers->toAnnotatedWord(i));
        }
    }
    return sentence;
}

AnnotatedSentence *ParseTreeDrawable::generateAnnotatedSentence(string language) {
    auto* sentence = new AnnotatedSentence();
    NodeDrawableCollector nodeDrawableCollector = NodeDrawableCollector((ParseNodeDrawable*)root, new IsTurkishLeafNode());
    vector<ParseNodeDrawable*> leafList = nodeDrawableCollector.collect();
    for (ParseNodeDrawable* parseNode : leafList){
        auto* newWord = new AnnotatedWord("{" + language + "=" + parseNode->getData().getName() + "}{posTag="
                                                  + parseNode->getParent()->getData().getName() + "}");
        sentence->addWord(newWord);
    }
    return sentence;
}
