//
// Created by olcay on 2019-05-13.
//

#include "ParseNodeSearchable.h"

/**
 * Constructs a ParseNodeSearchable from a xml node. If the node is a leaf node, it only sets the search type, layer
 * name and value. Otherwise, it only sets the parent node. It also calls itself recursively to generate its child
 * parseNodes.
 * @param parent The parent node of this node.
 * @param node Xml node that contains the node information.
 */
ParseNodeSearchable::ParseNodeSearchable(ParseNodeSearchable* parent, const XmlElement* node) {
    XmlElement* child;
    this->parent = parent;
    isLeafNode = node->getName() == "leaf";
    if (node->hasAttributes()){
        for (int i = 0; i < node->attributeSize(); i++){
            XmlAttribute attribute = node->getAttribute(i);
            string viewLayerType = attribute.getName().substr(0, 3);
            string searchType = attribute.getName().substr(3);
            searchValues.emplace_back(attribute.getValue());
            if (searchType == "equals"){
                searchTypes.emplace_back(SearchType::EQUALS);
            } else {
                if (searchType == "contains"){
                    searchTypes.emplace_back(SearchType::CONTAINS);
                } else {
                    if (searchType == "matches"){
                        searchTypes.emplace_back(SearchType::MATCHES);
                    } else {
                        if (searchType == "starts"){
                            searchTypes.emplace_back(SearchType::STARTS);
                        } else {
                            if (searchType == "ends"){
                                searchTypes.emplace_back(SearchType::ENDS);
                            } else {
                                if (searchType == "equalsignorecase"){
                                    searchTypes.emplace_back(SearchType::EQUALS_IGNORE_CASE);
                                } else {
                                    if (searchType == "isnull"){
                                        searchTypes.emplace_back(SearchType::IS_NULL);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (viewLayerType == "mor" || viewLayerType == "inf"){
                viewLayerTypes.emplace_back(ViewLayerType::INFLECTIONAL_GROUP);
            } else {
                if (viewLayerType == "tur"){
                    viewLayerTypes.emplace_back(ViewLayerType::TURKISH_WORD);
                } else {
                    if (viewLayerType == "per"){
                        viewLayerTypes.emplace_back(ViewLayerType::PERSIAN_WORD);
                    } else {
                        if (viewLayerType == "eng"){
                            viewLayerTypes.emplace_back(ViewLayerType::ENGLISH_WORD);
                        } else {
                            if (viewLayerType == "ner"){
                                viewLayerTypes.emplace_back(ViewLayerType::NER);
                            } else {
                                if (viewLayerType == "sem" || viewLayerType == "tse"){
                                    viewLayerTypes.emplace_back(ViewLayerType::SEMANTICS);
                                } else {
                                    if (viewLayerType == "met"){
                                        viewLayerTypes.emplace_back(ViewLayerType::META_MORPHEME);
                                    } else {
                                        if (viewLayerType == "pro"){
                                            viewLayerTypes.emplace_back(ViewLayerType::PROPBANK);
                                        } else {
                                            if (viewLayerType == "dep"){
                                                viewLayerTypes.emplace_back(ViewLayerType::DEPENDENCY);
                                            } else {
                                                if (viewLayerType == "sha" || viewLayerType == "chu"){
                                                    viewLayerTypes.emplace_back(ViewLayerType::SHALLOW_PARSE);
                                                } else {
                                                    if (viewLayerType == "ese"){
                                                        viewLayerTypes.emplace_back(ViewLayerType::ENGLISH_SEMANTICS);
                                                    } else {
                                                        if (viewLayerType == "epr"){
                                                            viewLayerTypes.emplace_back(ViewLayerType::ENGLISH_PROPBANK);
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
    child = node->getFirstChild();
    while (child != nullptr){
        if (child->getName() == "node" || child->getName() == "leaf")
            children.emplace_back(new ParseNodeSearchable(this, child));
        child = child->getNextSibling();
    }
}

/**
 * Accessor for the search type at the given position
 * @param index Position of the search type
 * @return Search type at the given position index.
 */
SearchType ParseNodeSearchable::getType(int index) const{
    return searchTypes.at(index);
}

/**
 * Accessor for the search value at the given position
 * @param index Position of the search value
 * @return Search value at the given position index.
 */
string ParseNodeSearchable::getValue(int index) const{
    return searchValues.at(index);
}

/**
 * Accessor for the layer name at the given position
 * @param index Position of the layer name
 * @return Layer name at the given position index.
 */
ViewLayerType ParseNodeSearchable::getViewLayerType(int index) const{
    return viewLayerTypes.at(index);
}

/**
 * Accessor for the isLeaf attribute
 * @return IsLeaf attribute
 */
bool ParseNodeSearchable::isLeaf() const{
    return isLeafNode;
}

int ParseNodeSearchable::size() const{
    return searchValues.size();
}
