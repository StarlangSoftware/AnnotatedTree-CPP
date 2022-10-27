//
// Created by olcay on 2019-05-13.
//

#include <istream>
#include "ParseTreeDrawable.h"
#include "ParseNodeDrawable.h"
#include "Processor/NodeDrawableCollector.h"
#include "Processor/Condition/IsTurkishLeafNode.h"
#include "Processor/Condition/IsEnglishLeafNode.h"

ParseTreeDrawable::ParseTreeDrawable(const string& path, const string& rawFileName) : ParseTreeDrawable(FileDescription(path, rawFileName)){
}

ParseTreeDrawable::ParseTreeDrawable(const string &path, const string &extension, int index) : ParseTreeDrawable(FileDescription(path, extension, index)){
}

ParseTreeDrawable::ParseTreeDrawable(const string& path, const FileDescription& fileDescription) : ParseTreeDrawable(path, fileDescription.getExtension(), fileDescription.getIndex()) {
}

ParseTreeDrawable::ParseTreeDrawable(const FileDescription& fileDescription) {
    this->fileDescription = fileDescription;
    readFromFile(fileDescription.getPath());
}

void ParseTreeDrawable::setFileDescription(const FileDescription& fileDescription) {
    this->fileDescription = fileDescription;
}

FileDescription ParseTreeDrawable::getFileDescription() const{
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

ParseTreeDrawable::ParseTreeDrawable(const string& line) {
    string _line = line;
    _line = Word::replaceAll(_line, "\n", "");
    _line = Word::replaceAll(_line, "\t", "");
    if (_line.find('(') != string::npos && _line.find(')') != string::npos){
        _line = Word::trim(_line.substr(_line.find('(') + 1, _line.find_last_of(')') - _line.find('(')));
        root = new ParseNodeDrawable(nullptr, _line, false, 0);
    }
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
    outputFile.open(fileDescription.getFileName(), ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

void ParseTreeDrawable::saveWithPath(const string& newPath) {
    ofstream outputFile;
    outputFile.open(fileDescription.getFileName(newPath), ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

int ParseTreeDrawable::glossAgreementCount(const ParseTree& parseTree, ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)root)->glossAgreementCount((ParseNodeDrawable*) parseTree.getRoot(), viewLayerType);
}

int ParseTreeDrawable::structureAgreementCount(const ParseTree& parseTree) const{
    return ((ParseNodeDrawable*)root)->structureAgreementCount((ParseNodeDrawable*)parseTree.getRoot());
}

int ParseTreeDrawable::maxDepth() const{
    return ((ParseNodeDrawable*) root)->maxDepth();
}

bool ParseTreeDrawable::layerExists(ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)(root))->layerExists(viewLayerType);
}

bool ParseTreeDrawable::layerAll(ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)(root))->layerAll(viewLayerType);
}

void ParseTreeDrawable::clearLayer(ViewLayerType layerType) {
    if (root != nullptr){
        ((ParseNodeDrawable*)root)->clearLayer(layerType);
    }
}

vector<ParseNodeDrawable*> ParseTreeDrawable::satisfy(const ParseTreeSearchable& tree) const{
    return ((ParseNodeDrawable*)root)->satisfy(tree);
}

AnnotatedSentence* ParseTreeDrawable::generateAnnotatedSentence() const{
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

AnnotatedSentence *ParseTreeDrawable::generateAnnotatedSentence(const string& language) const{
    auto* sentence = new AnnotatedSentence();
    NodeDrawableCollector nodeDrawableCollector = NodeDrawableCollector((ParseNodeDrawable*)root, new IsEnglishLeafNode());
    vector<ParseNodeDrawable*> leafList = nodeDrawableCollector.collect();
    for (ParseNodeDrawable* parseNode : leafList){
        string leafWord = parseNode->getData().getName();
        string parentWord = parseNode->getParent()->getData().getName();
        string word = "{" + language + "=" + leafWord + "}{posTag=" + parentWord + "}";
        auto* newWord = new AnnotatedWord(word);
        sentence->addWord(newWord);
    }
    return sentence;
}

ParseTree *ParseTreeDrawable::generateParseTree(bool surfaceForm) const{
    auto* result = new ParseTree(new ParseNode(root->getData()));
    ((ParseNodeDrawable*) root)->generateParseNode(result->getRoot(), surfaceForm);
    return result;
}
