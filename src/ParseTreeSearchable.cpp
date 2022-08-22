//
// Created by olcay on 2019-05-13.
//

#include "ParseTreeSearchable.h"
#include "ParseNodeSearchable.h"

ParseTreeSearchable::ParseTreeSearchable(XmlElement* rootNode) {
    root = new ParseNodeSearchable(nullptr, rootNode);
}
