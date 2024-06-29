//
// Created by olcay on 2019-05-13.
//

#ifndef ANNOTATEDTREE_PARSETREEDRAWABLE_H
#define ANNOTATEDTREE_PARSETREEDRAWABLE_H

#include <ViewLayerType.h>
#include <AnnotatedSentence.h>
#include "ParseTree.h"
#include "FileDescription.h"
#include "ParseTreeSearchable.h"
#include "ParseNodeDrawable.h"

class ParseTreeDrawable : public ParseTree{
private:
    FileDescription fileDescription = FileDescription("mypath", "0000.train");
    void readFromFile(const string& currentPath);
public:
    ParseTreeDrawable(const string& path, const string& rawFileName);
    ParseTreeDrawable(const string& path, const string& extension, int index);
    ParseTreeDrawable(const string& path, const FileDescription& fileDescription);
    explicit ParseTreeDrawable(istream& inputFile);
    explicit ParseTreeDrawable(const string& line);
    explicit ParseTreeDrawable(const FileDescription& fileDescription);
    void setFileDescription(const FileDescription& _fileDescription);
    FileDescription getFileDescription() const;
    void copyInfo(const ParseTreeDrawable& parseTree);
    void reload();
    void nextTree(int count);
    void previousTree(int count);
    void save();
    void saveWithPath(const string& newPath);
    int glossAgreementCount(const ParseTree& parseTree, ViewLayerType viewLayerType) const;
    int structureAgreementCount(const ParseTree& parseTree) const;
    int maxDepth() const;
    bool layerExists(ViewLayerType viewLayerType) const;
    bool layerAll(ViewLayerType viewLayerType) const;
    void clearLayer(ViewLayerType layerType);
    vector<ParseNodeDrawable*> satisfy(const ParseTreeSearchable& tree) const;
    AnnotatedSentence* generateAnnotatedSentence() const;
    AnnotatedSentence* generateAnnotatedSentence(const string& language) const;
    ParseTree* generateParseTree(bool surfaceForm) const;
};


#endif //ANNOTATEDTREE_PARSETREEDRAWABLE_H
