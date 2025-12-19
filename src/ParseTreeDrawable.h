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
    [[nodiscard]] FileDescription getFileDescription() const;
    void copyInfo(const ParseTreeDrawable& parseTree);
    void reload();
    void nextTree(int count);
    void previousTree(int count);
    void save() const;
    void saveWithPath(const string& newPath) const;
    [[nodiscard]] int glossAgreementCount(const ParseTree& parseTree, ViewLayerType viewLayerType) const;
    [[nodiscard]] int structureAgreementCount(const ParseTree& parseTree) const;
    [[nodiscard]] int maxDepth() const;
    [[nodiscard]] bool layerExists(ViewLayerType viewLayerType) const;
    [[nodiscard]] bool layerAll(ViewLayerType viewLayerType) const;
    void clearLayer(ViewLayerType layerType) const;
    [[nodiscard]] vector<ParseNodeDrawable*> satisfy(const ParseTreeSearchable& tree) const;
    [[nodiscard]] AnnotatedSentence* generateAnnotatedSentence() const;
    [[nodiscard]] AnnotatedSentence* generateAnnotatedSentence(const string& language) const;
    [[nodiscard]] ParseTree* generateParseTree(bool surfaceForm) const;
};


#endif //ANNOTATEDTREE_PARSETREEDRAWABLE_H
