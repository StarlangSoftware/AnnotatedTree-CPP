//
// Created by olcay on 2019-05-16.
//

#include "AutoArgument.h"
#include "../../Processor/NodeDrawableCollector.h"
#include "../../Processor/Condition/IsTransferable.h"

AutoArgument::AutoArgument(ViewLayerType secondLanguage) {
    this->secondLanguage = secondLanguage;
}

void AutoArgument::autoArgument(ParseTreeDrawable* parseTree, Frameset frameset) {
    ArgumentType values[] = {ArgumentType::NONE, ArgumentType::PREDICATE, ArgumentType::ARG0, ArgumentType::ARG1, ArgumentType::ARG2, ArgumentType::ARG3, ArgumentType::ARG4, ArgumentType::ARG5, ArgumentType::ARGMNONE, ArgumentType::ARGMEXT, ArgumentType::ARGMLOC, ArgumentType::ARGMDIS, ArgumentType::ARGMADV, ArgumentType::ARGMCAU, ArgumentType::ARGMTMP, ArgumentType::ARGMPNC, ArgumentType::ARGMMNR, ArgumentType::ARGMDIR};
    NodeDrawableCollector nodeDrawableCollector = NodeDrawableCollector((ParseNodeDrawable*) parseTree->getRoot(), new IsTransferable(secondLanguage));
    vector<ParseNodeDrawable*> leafList = nodeDrawableCollector.collect();
    for (ParseNodeDrawable* parseNode : leafList){
        if (parseNode->getLayerData(ViewLayerType::PROPBANK).empty()){
            for (ArgumentType argumentType : values){
                if (frameset.containsArgument(argumentType) && autoDetectArgument(parseNode, argumentType)){
                    parseNode->getLayerInfo()->setLayerData(ViewLayerType::PROPBANK, getPropbankType(argumentType));
                }
            }
            if (Word::isPunctuation(parseNode->getLayerData(secondLanguage))){
                parseNode->getLayerInfo()->setLayerData(ViewLayerType::PROPBANK, "NONE");
            }
        }
    }
    parseTree->save();
}
