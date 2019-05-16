//
// Created by olcay on 2019-05-16.
//

#include "TurkishAutoArgument.h"

TurkishAutoArgument::TurkishAutoArgument() : AutoArgument(ViewLayerType::TURKISH_WORD){

}

bool TurkishAutoArgument::checkAncestors(ParseNode* parseNode, const string &name) {
    while (parseNode != nullptr){
        if (parseNode->getData().getName() == name){
            return true;
        }
        parseNode = parseNode->getParent();
    }
    return false;
}

bool TurkishAutoArgument::checkAncestorsUntil(ParseNode* parseNode, const string &suffix) {
    while (parseNode != nullptr){
        if (parseNode->getData().getName().find("-" + suffix) != string::npos){
            return true;
        }
        parseNode = parseNode->getParent();
    }
    return false;
}

bool TurkishAutoArgument::autoDetectArgument(ParseNodeDrawable *parseNode, ArgumentType argumentType) {
    ParseNode* parent = parseNode->getParent();
    switch (argumentType){
        case ArgumentType::ARG0:
            if (checkAncestorsUntil(parent, "SBJ")){
                return true;
            }
            break;
        case ArgumentType::ARG1:
            if (checkAncestorsUntil(parent, "OBJ")){
                return true;
            }
            break;
        case ArgumentType::ARGMADV:
            if (checkAncestorsUntil(parent, "ADV")){
                return true;
            }
            break;
        case ArgumentType::ARGMTMP:
            if (checkAncestorsUntil(parent, "TMP")){
                return true;
            }
            break;
        case ArgumentType::ARGMMNR:
            if (checkAncestorsUntil(parent, "MNR")){
                return true;
            }
            break;
        case ArgumentType::ARGMLOC:
            if (checkAncestorsUntil(parent, "LOC")){
                return true;
            }
            break;
        case ArgumentType::ARGMDIR:
            if (checkAncestorsUntil(parent, "DIR")){
                return true;
            }
            break;
        case ArgumentType::ARGMDIS:
            if (checkAncestors(parent, "CC")){
                return true;
            }
            break;
        case ArgumentType::ARGMEXT:
            if (checkAncestorsUntil(parent, "EXT")){
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}
