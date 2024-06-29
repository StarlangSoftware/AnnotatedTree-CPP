//
// Created by olcay on 2019-05-13.
//

#include "ParseTreeSearchable.h"
#include "ParseNodeSearchable.h"

/**
 * Construct a ParseTreeSearchable from a xml element.
 * @param rootNode XmlElement that contains the root node information.
 */
ParseTreeSearchable::ParseTreeSearchable(XmlElement* rootNode) {
    root = new ParseNodeSearchable(nullptr, rootNode);
}
