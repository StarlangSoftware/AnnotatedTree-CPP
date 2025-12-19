//
// Created by olcay on 2019-05-13.
//

#ifndef ANNOTATEDTREE_SEARCHTREE_H
#define ANNOTATEDTREE_SEARCHTREE_H

#include <vector>
#include "ParseTreeSearchable.h"
#include "ParseTreeDrawable.h"

class SearchTree {
private:
    vector<ParseTreeSearchable> searchTrees;
public:
    explicit SearchTree(const string& fileName);
    [[nodiscard]] vector<ParseNode*> satisfy(const ParseTreeDrawable& tree) const;
};


#endif //ANNOTATEDTREE_SEARCHTREE_H
