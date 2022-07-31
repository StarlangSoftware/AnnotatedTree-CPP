//
// Created by Olcay Taner YILDIZ on 8.01.2021.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../ParseTreeDrawable.h"
#include "../TreeBankDrawable.h"

TEST_CASE("ParseTreeDrawableTest-testGenerateParseTree") {
    ParseTreeDrawable *tree0;
    ParseTree* tree;
    ifstream inputFile;
    inputFile.open("../trees/0000.dev", ifstream::in);
    tree0 = new ParseTreeDrawable(inputFile);
    tree = tree0->generateParseTree(true);
    REQUIRE("(S (NP (NP (ADJP (ADJP yeni) (ADJP Büyük))  (NP yasada))  (NP (ADJP karmaşık) (NP dil)) )  (VP (NP savaşı) (VP bulandırmıştır))  (. .)) " == tree->to_string());
    tree = tree0->generateParseTree(false);
    REQUIRE("(S (NP (NP (ADJP (ADJP yeni) (ADJP büyük))  (NP yasa))  (NP (ADJP karmaşık) (NP dil)) )  (VP (NP savaş) (VP bulan))  (. .)) " == tree->to_string());
    inputFile.close();
}

TEST_CASE("ParseTreeDrawableTest-testMaxDepth") {
    TreeBankDrawable* treeBank;
    treeBank = new TreeBankDrawable("../trees");
    REQUIRE(5 == treeBank->get(0)->maxDepth());
    REQUIRE(5 == treeBank->get(1)->maxDepth());
    REQUIRE(5 == treeBank->get(2)->maxDepth());
    REQUIRE(5 == treeBank->get(3)->maxDepth());
    REQUIRE(6 == treeBank->get(4)->maxDepth());
    REQUIRE(3 == treeBank->get(5)->maxDepth());
    REQUIRE(4 == treeBank->get(6)->maxDepth());
    REQUIRE(6 == treeBank->get(7)->maxDepth());
    REQUIRE(5 == treeBank->get(8)->maxDepth());
    REQUIRE(6 == treeBank->get(9)->maxDepth());
}
