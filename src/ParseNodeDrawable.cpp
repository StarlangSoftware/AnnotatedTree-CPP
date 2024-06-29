//
// Created by Olcay Taner YILDIZ on 2019-05-12.
//

#include "ParseNodeDrawable.h"
#include "ParseNodeSearchable.h"

/**
 * Constructs a ParseNodeDrawable from a single line. If the node is a leaf node, it only sets the data. Otherwise,
 * splits the line w.r.t. spaces and parenthesis and calls itself recursively to generate its child parseNodes.
 * @param parent The parent node of this node.
 * @param line The input line to create this parseNode.
 * @param isLeaf True, if this node is a leaf node; false otherwise.
 * @param depth Depth of the node.
 */
ParseNodeDrawable::ParseNodeDrawable(ParseNodeDrawable *parent, const string& line, bool isLeaf, int depth) {
    int parenthesisCount = 0;
    string childLine;
    this->depth = depth;
    this->parent = parent;
    if (isLeaf){
        if (line.find('{') == string::npos){
            data = Symbol(line);
        } else {
            layers = new LayerInfo(line);
        }
    } else {
        int startPos = line.find(' ');
        data = Symbol(line.substr(1, startPos - 1));
        if (line.find_first_of(')') == line.find_last_of(')')){
            children.emplace_back(new ParseNodeDrawable(this, line.substr(startPos + 1, line.find(")") - startPos - 1), true, depth + 1));
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

/**
 * Another simple constructor for ParseNode. It only takes input the data, and sets it.
 * @param data Data for this node.
 */
ParseNodeDrawable::ParseNodeDrawable(const Symbol& data) : ParseNode(data) {
}

/**
 * Another constructor for ParseNodeDrawable. Sets the parent to the given parent, and adds given child as a
 * single child, and sets the given symbol as data.
 * @param parent Parent of this node.
 * @param child Single child of this node.
 * @param symbol Symbol of this node.
 */
ParseNodeDrawable::ParseNodeDrawable(ParseNodeDrawable *parent, ParseNodeDrawable *child, const string& symbol) {
    this->depth = child->depth;
    child->updateDepths(this->depth + 1);
    this->parent = parent;
    this->parent->setChild(parent->getChildIndex(child), this);
    this->children.emplace_back(child);
    child->parent = this;
    this->data = Symbol(symbol);
}

/**
 * Accessor for layers attribute
 * @return Layers attribute
 */
LayerInfo* ParseNodeDrawable::getLayerInfo() const{
    return layers;
}

/**
 * Returns the data. Either the node is a leaf node, in which case English word layer is returned; or the node is
 * a nonleaf node, in which case the node tag is returned.
 * @return English word for leaf node, constituency tag for non-leaf node.
 */
Symbol ParseNodeDrawable::getData() const{
    if (layers == nullptr){
        return ParseNode::getData();
    } else {
        return Symbol(getLayerData(ViewLayerType::ENGLISH_WORD));
    }
}

/**
 * Clears the layers hash map.
 */
void ParseNodeDrawable::clearLayers() {
    layers = new LayerInfo();
}

/**
 * Recursive method to clear a given layer.
 * @param layerType Name of the layer to be cleared
 */
void ParseNodeDrawable::clearLayer(ViewLayerType layerType) {
    if (children.empty() && layerExists(layerType)){
        layers->removeLayer(layerType);
    }
    for (int i = 0; i < numberOfChildren(); i++){
        ((ParseNodeDrawable*) children.at(i))->clearLayer(layerType);
    }
}

/**
 * Clears the node tag.
 */
void ParseNodeDrawable::clearData() {
    data = Symbol("");
}

/**
 * Setter for the data attribute and also clears all layers.
 * @param data New data field.
 */
void ParseNodeDrawable::setDataAndClearLayers(const Symbol& data) {
    ParseNode::setData(data);
    layers = nullptr;
}

/**
 * Mutator for the data field. If the layers is null, its sets the data field, otherwise it sets the English layer
 * to the given value.
 * @param data Data to be set.
 */
void ParseNodeDrawable::setData(const Symbol& data) {
    if (layers == nullptr){
        ParseNode::setData(data);
    } else {
        layers->setLayerData(ViewLayerType::ENGLISH_WORD, data.getName());
    }
}

/**
 * Returns the layer value of the head child of this node.
 * @param viewLayerType Layer name
 * @return Layer value of the head child of this node.
 */
string ParseNodeDrawable::headWord(ViewLayerType viewLayerType) const{
    if (!children.empty()){
        return ((ParseNodeDrawable*) headChild())->headWord(viewLayerType);
    } else {
        return getLayerData(viewLayerType);
    }
}

/**
 * Accessor for the data or layers attribute.
 * @return If data is not null, this node is a non-leaf node, it returns the data field. Otherwise, this node is a
 * leaf node, it returns the layer description.
 */
string ParseNodeDrawable::getLayerData() const{
    if (!data.getName().empty())
        return data.getName();
    return layers->getLayerDescription();
}

/**
 * Returns the layer value of a given layer.
 * @param viewLayer Layer name
 * @return Value of the given layer
 */
string ParseNodeDrawable::getLayerData(ViewLayerType viewLayer) const{
    if (viewLayer == ViewLayerType::WORD || layers == nullptr)
        return data.getName();
    return layers->getLayerData(viewLayer);
}

/**
 * Accessor for the depth attribute
 * @return Depth attribute
 */
int ParseNodeDrawable::getDepth() const{
    return depth;
}

/**
 * Returns the number of structural agreement between this node and the given node recursively. Two nodes agree in
 * structural manner if they have the same number of children and all of their children have the same tags in the
 * same order.
 * @param parseNode Parse node to compare in structural manner
 * @return The number of structural agreement between this node and the given node recursively.
 */
int ParseNodeDrawable::structureAgreementCount(ParseNodeDrawable *parseNode) const{
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

/**
 * Returns the number of gloss agreements between this node and the given node recursively. Two nodes agree in
 * glosses if they are both leaf nodes and their layer info are the same.
 * @param parseNode Parse node to compare in gloss manner
 * @param viewLayerType Layer name to compare
 * @return The number of gloss agreements between this node and the given node recursively.
 */
int ParseNodeDrawable::glossAgreementCount(ParseNodeDrawable* parseNode, ViewLayerType viewLayerType) const{
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

/**
 * Recursive method which updates the depth attribute
 * @param depth Current depth to set.
 */
void ParseNodeDrawable::updateDepths(int _depth){
    this->depth = _depth;
    for (ParseNode* aChildren:children){
        auto * aChild = (ParseNodeDrawable*) aChildren;
        aChild->updateDepths(_depth + 1);
    }
}

/**
 * Calculates the maximum depth of the subtree rooted from this node.
 * @return The maximum depth of the subtree rooted from this node.
 */
int ParseNodeDrawable::maxDepth() const{
    int _depth = this->depth;
    for (ParseNode* aChildren : children) {
        auto* aChild = (ParseNodeDrawable*) aChildren;
        if (aChild->maxDepth() > _depth)
            _depth = aChild->maxDepth();
    }
    return _depth;
}

/**
 * Recursive method that returns the concatenation of all pos tags of all descendants of this node.
 * @return The concatenation of all pos tags of all descendants of this node.
 */
string ParseNodeDrawable::ancestorString() const{
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

/**
 * Recursive method that checks if all nodes in the subtree rooted with this node has the annotation in the given
 * layer.
 * @param viewLayerType Layer name
 * @return True if all nodes in the subtree rooted with this node has the annotation in the given layer, false
 * otherwise.
 */
bool ParseNodeDrawable::layerExists(ViewLayerType viewLayerType) const{
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

/**
 * Checks if the current node is a dummy node or not. A node is a dummy node if its data contains '*', or its
 * data is '0' and its parent is '-NONE-'.
 * @return True if the current node is a dummy node, false otherwise.
 */
bool ParseNodeDrawable::isDummyNode() const{
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

/**
 * Checks if all nodes in the subtree rooted with this node has annotation with the given layer.
 * @param viewLayerType Layer name
 * @return True if all nodes in the subtree rooted with this node has annotation with the given layer, false
 * otherwise.
 */
bool ParseNodeDrawable::layerAll(ViewLayerType viewLayerType) const{
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

/**
 * Recursive method to convert the subtree rooted with this node to a string. All parenthesis types are converted to
 * their regular forms.
 * @return String version of the subtree rooted with this node.
 */
string ParseNodeDrawable::toTurkishSentence() const{
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

/**
 * Sets the NER layer according to the tag of the parent node and the word in the node. The word is searched in the
 * gazetteer, if it exists, the NER info is replaced with the NER tag in the gazetter.
 * @param gazetteer Gazetter where we search the word
 * @param word Word to be searched in the gazetter
 */
void ParseNodeDrawable::checkGazetteer(Gazetteer& gazetteer, const string& word){
    if (gazetteer.contains(word) && getParent()->getData().getName() == "NNP"){
        getLayerInfo()->setLayerData(ViewLayerType::NER, gazetteer.getName());
    }
    if (word.find("'") != string::npos && gazetteer.contains(word.substr(0, word.find("'"))) && getParent()->getData().getName() == "NNP"){
        getLayerInfo()->setLayerData(ViewLayerType::NER, gazetteer.getName());
    }
}

/**
 * Recursive method to convert the subtree rooted with this node to a string.
 * @return String version of the subtree rooted with this node.
 */
string ParseNodeDrawable::to_string() const{
    if (children.size() < 2){
        if (children.size() < 1){
            return getLayerData();
        } else {
            return "(" + data.getName() + " " + children.at(0)->to_string() + ")";
        }
    } else {
        string st = "(" + data.getName();
        for (ParseNode* aChild : children) {
            st += " " + aChild->to_string();
        }
        return st + ") ";
    }
}

/**
 * Recursive method that checks if the current node satisfies the conditions in the given search node.
 * @param node Node containing the search condition
 * @return True if the node satisfies the condition, false otherwise.
 */
bool ParseNodeDrawable::satisfy(ParseNodeSearchable* node) const{
    int i;
    if (node->isLeaf() && children.size() > 0)
        return false;
    for (i = 0; i < node->size(); i++){
        ViewLayerType viewLayer = node->getViewLayerType(i);
        string data = node->getValue(i);
        if (getLayerData(viewLayer).empty() && node->getType(i) != SearchType::EQUALS && node->getType(i) != SearchType::IS_NULL){
            return false;
        }
        switch (node->getType(i)) {
            case SearchType::CONTAINS:
                if (getLayerData(viewLayer).find(data) == string::npos) {
                    return false;
                }
                break;
            case SearchType::EQUALS:
                if (getLayerData(viewLayer).empty()) {
                    if (!node->getValue(i).empty()) {
                        return false;
                    }
                } else {
                    if (getLayerData(viewLayer) != data) {
                        return false;
                    }
                }
                break;
            case SearchType::EQUALS_IGNORE_CASE:
                if (getLayerData(viewLayer) != data) {
                    return false;
                }
                break;
            case SearchType::STARTS:
                if (!Word::startsWith(getLayerData(viewLayer), data)) {
                    return false;
                }
                break;
            case SearchType::ENDS:
                if (!Word::endsWith(getLayerData(viewLayer), data)) {
                    return false;
                }
                break;
            case SearchType::IS_NULL:
                if (!getLayerData(viewLayer).empty()) {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
    if (node->numberOfChildren() > children.size()){
        return false;
    }
    for (i = 0; i < children.size(); i++){
        if (i < node->numberOfChildren() && !((ParseNodeDrawable*)getChild(i))->satisfy((ParseNodeSearchable*)node->getChild(i))){
            return false;
        }
    }
    return true;
}

/**
 * Recursive method that returns all nodes in the subtree rooted with this node those satisfy the conditions in the
 * given tree.
 * @param tree Tree containing the search condition
 * @return All nodes in the subtree rooted with this node those satisfy the conditions in the given tree.
 */
vector<ParseNodeDrawable*> ParseNodeDrawable::satisfy(const ParseTreeSearchable& tree){
    vector<ParseNodeDrawable*> result;
    if (satisfy((ParseNodeSearchable*)(tree.getRoot()))){
        result.emplace_back(this);
    }
    for (ParseNode* child:children){
        vector<ParseNodeDrawable*> list = ((ParseNodeDrawable*)child)->satisfy(tree);
        result.insert(result.end(), list.begin(), list.end());
    }
    return result;
}

/**
 * Recursive method that sets the tag information of the given parse node with all descendants with respect to the
 * morphological annotation of the current node with all descendants.
 * @param parseNode Parse node whose tag information will be changed.
 * @param surfaceForm If true, tag will be replaced with the surface form annotation.
 */
void ParseNodeDrawable::generateParseNode(ParseNode *parseNode, bool surfaceForm) const{
    if (numberOfChildren() == 0){
        if (surfaceForm){
            parseNode->setData(Symbol(getLayerData(ViewLayerType::TURKISH_WORD)));
        } else {
            parseNode->setData(Symbol(getLayerInfo()->getMorphologicalParseAt(0).getWord()->getName()));
        }
    } else {
        parseNode->setData(data);
        for (int i = 0; i < numberOfChildren(); i++){
            auto* newChild = new ParseNode();
            parseNode->addChild(newChild);
            ((ParseNodeDrawable*) children[i])->generateParseNode(newChild, surfaceForm);
        }
    }
}
