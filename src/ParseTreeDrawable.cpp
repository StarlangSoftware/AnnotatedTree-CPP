//
// Created by olcay on 2019-05-13.
//

#include <istream>
#include "ParseTreeDrawable.h"
#include "ParseNodeDrawable.h"
#include "Processor/NodeDrawableCollector.h"
#include "Processor/Condition/IsTurkishLeafNode.h"
#include "Processor/Condition/IsEnglishLeafNode.h"

/**
 * Constructor for the ParseTreeDrawable. Sets the file description and reads the tree from the file description.
 * @param path Path of the tree
 * @param rawFileName File name of the tree such as 0123.train.
 */
ParseTreeDrawable::ParseTreeDrawable(const string& path, const string& rawFileName) : ParseTreeDrawable(FileDescription(path, rawFileName)){
}

/**
 * Another constructor for the ParseTreeDrawable. Sets the file description and reads the tree from the file
 * description.
 * @param path Path of the tree
 * @param extension Extension of the file such as train, test or dev.
 * @param index Index of the file such as 1235.
 */
ParseTreeDrawable::ParseTreeDrawable(const string &path, const string &extension, int index) : ParseTreeDrawable(FileDescription(path, extension, index)){
}

/**
 * Another constructor for the ParseTreeDrawable. Sets the file description and reads the tree from the file
 * description.
 * @param path Path of the tree
 * @param fileDescription File description that contains the path, index and extension information.
 */
ParseTreeDrawable::ParseTreeDrawable(const string& path, const FileDescription& fileDescription) : ParseTreeDrawable(path, fileDescription.getExtension(), fileDescription.getIndex()) {
}

/**
 * Another constructor for the ParseTreeDrawable. Sets the file description and reads the tree from the file
 * description.
 * @param fileDescription File description that contains the path, index and extension information.
 */
ParseTreeDrawable::ParseTreeDrawable(const FileDescription& fileDescription) {
    this->fileDescription = fileDescription;
    readFromFile(fileDescription.getFileName());
}

/**
 * Mutator method for the fileDescription attribute.
 * @param fileDescription New fileDescription value.
 */
void ParseTreeDrawable::setFileDescription(const FileDescription& _fileDescription) {
    this->fileDescription = _fileDescription;
}

/**
 * Accessor method for the fileDescription attribute.
 * @return FileDescription attribute.
 */
FileDescription ParseTreeDrawable::getFileDescription() const{
    return fileDescription;
}

/**
 * Copies the file description information from the given parse tree.
 * @param parseTree Parse tree whose file description information will be copied.
 */
void ParseTreeDrawable::copyInfo(const ParseTreeDrawable& parseTree) {
    this->fileDescription = parseTree.fileDescription;
}

/**
 * Reloads the tree from the input file.
 */
void ParseTreeDrawable::reload() {
    readFromFile(fileDescription.getFileName());
}

/**
 * Reads the parse tree from the given line. It sets the root node which calls ParseNodeDrawable constructor
 * recursively.
 * @param line Line containing the definition of the tree.
 */
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

/**
 * Another constructor of the ParseTree. The method takes the file containing a single line as input and constructs
 * the whole tree by calling the ParseNode constructor recursively.
 * @param inputFile File containing a single line for a ParseTree
 */
ParseTreeDrawable::ParseTreeDrawable(istream &inputFile) {
    string line;
    getline(inputFile, line);
    if (line.find('(') != string::npos && line.find(')') != string::npos){
        line = Word::trim(line.substr(line.find('(') + 1, line.find_last_of(')') - line.find('(')));
        root = new ParseNodeDrawable(nullptr, line, false, 0);
    }
}

/**
 * Another constructor of the ParseTree. The method takes the line as input and constructs
 * the whole tree by calling the ParseNode constructor recursively.
 * @param line Line for a ParseTree
 */
ParseTreeDrawable::ParseTreeDrawable(const string& line) {
    string _line = line;
    _line = Word::replaceAll(_line, "\n", "");
    _line = Word::replaceAll(_line, "\t", "");
    if (_line.find('(') != string::npos && _line.find(')') != string::npos){
        _line = Word::trim(_line.substr(_line.find('(') + 1, _line.find_last_of(')') - _line.find('(')));
        root = new ParseNodeDrawable(nullptr, _line, false, 0);
    }
}

/**
 * Loads the next tree according to the index of the parse tree. For example, if the current
 * tree fileName is 0123.train, after the call of nextTree(3), the method will load 0126.train. If the next tree
 * does not exist, nothing will happen.
 * @param count Number of trees to go forward
 */
void ParseTreeDrawable::nextTree(int count) {
    fileDescription.addToIndex(count);
    reload();
}

/**
 * Loads the previous tree according to the index of the parse tree. For example, if the current
 * tree fileName is 0123.train, after the call of previousTree(4), the method will load 0119.train. If the
 * previous tree does not exist, nothing will happen.
 * @param count Number of trees to go backward
 */
void ParseTreeDrawable::previousTree(int count) {
    fileDescription.addToIndex(-count);
    reload();
}

/**
 * Saves current tree.
 */
void ParseTreeDrawable::save() {
    ofstream outputFile;
    outputFile.open(fileDescription.getFileName(), ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

/**
 * Saves current tree to the newPath with other file properties staying the same.
 * @param newPath Path to which tree will be saved
 */
void ParseTreeDrawable::saveWithPath(const string& newPath) {
    ofstream outputFile;
    outputFile.open(fileDescription.getFileName(newPath), ios::out);
    outputFile << "(" + to_string() + ")\n";
    outputFile.close();
}

/**
 * Returns the number of gloss agreements between this tree and the given tree. Two nodes agree in
 * glosses if they are both leaf nodes and their layer info are the same.
 * @param parseTree Parse tree to compare in gloss manner
 * @param viewLayerType Layer name to compare
 * @return The number of gloss agreements between this node and the given node recursively.
 */
int ParseTreeDrawable::glossAgreementCount(const ParseTree& parseTree, ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)root)->glossAgreementCount((ParseNodeDrawable*) parseTree.getRoot(), viewLayerType);
}

/**
 * Returns the number of structural agreement between this tree and the given tree. Two nodes agree in
 * structural manner if they have the same number of children and all of their children have the same tags in the
 * same order.
 * @param parseTree Parse tree to compare in structural manner
 * @return The number of structural agreement between this tree and the given tree.
 */
int ParseTreeDrawable::structureAgreementCount(const ParseTree& parseTree) const{
    return ((ParseNodeDrawable*)root)->structureAgreementCount((ParseNodeDrawable*)parseTree.getRoot());
}

/**
 * Calculates the maximum depth of the tree.
 * @return The maximum depth of the tree.
 */
int ParseTreeDrawable::maxDepth() const{
    return ((ParseNodeDrawable*) root)->maxDepth();
}

/**
 * The method checks if all nodes in the tree has the annotation in the given layer.
 * @param viewLayerType Layer name
 * @return True if all nodes in the tree has the annotation in the given layer, false otherwise.
 */
bool ParseTreeDrawable::layerExists(ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)(root))->layerExists(viewLayerType);
}

/**
 * Checks if all nodes in the tree has annotation with the given layer.
 * @param viewLayerType Layer name
 * @return True if all nodes in the tree has annotation with the given layer, false otherwise.
 */
bool ParseTreeDrawable::layerAll(ViewLayerType viewLayerType) const{
    return ((ParseNodeDrawable*)(root))->layerAll(viewLayerType);
}

/**
 * Clears the given layer for all nodes in the tree
 * @param layerType Layer name
 */
void ParseTreeDrawable::clearLayer(ViewLayerType layerType) {
    if (root != nullptr){
        ((ParseNodeDrawable*)root)->clearLayer(layerType);
    }
}

vector<ParseNodeDrawable*> ParseTreeDrawable::satisfy(const ParseTreeSearchable& tree) const{
    return ((ParseNodeDrawable*)root)->satisfy(tree);
}

/**
 * Constructs an AnnotatedSentence object from the Turkish tree. Collects all leaf nodes, then for each leaf node
 * converts layer info of all words at that node to AnnotatedWords. Layers are converted to the counterparts in the
 * AnnotatedWord.
 * @return AnnotatedSentence counterpart of the Turkish tree
 */
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

/**
 * Constructs an AnnotatedSentence object from the English tree. Collects all leaf nodes, then for each leaf node
 * converts the word with its parents pos tag to AnnotatedWord.
 * @return AnnotatedSentence counterpart of the English tree
 */
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

/**
 * Recursive method that generates a new parse tree by replacing the tag information of the all parse nodes (with all
 * its descendants) with respect to the morphological annotation of all parse nodes (with all its descendants)
 * of the current parse tree.
 * @param surfaceForm If true, tag will be replaced with the surface form annotation.
 */
ParseTree *ParseTreeDrawable::generateParseTree(bool surfaceForm) const{
    auto* result = new ParseTree(new ParseNode(root->getData()));
    ((ParseNodeDrawable*) root)->generateParseNode(result->getRoot(), surfaceForm);
    return result;
}
