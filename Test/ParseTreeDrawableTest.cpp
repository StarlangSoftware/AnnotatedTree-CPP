//
// Created by Olcay Taner YILDIZ on 8.01.2021.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../ParseTreeDrawable.h"

TEST_CASE("ParseTreeDrawableTest-testGenerateParseTree") {
    ParseTreeDrawable *tree0;
    ParseTree* tree;
    ifstream inputFile;
    inputFile.open("trees/0000.dev", ifstream::in);
    tree0 = new ParseTreeDrawable(inputFile);
    tree = tree0->generateParseTree(true);
    REQUIRE("(S (NP (NP (ADJP (ADJP yeni) (ADJP Büyük))  (NP yasada))  (NP (ADJP karmaşık) (NP dil)) )  (VP (NP savaşı) (VP bulandırmıştır))  (. .)) " == tree->to_string());
    tree = tree0->generateParseTree(false);
    REQUIRE("(S (NP (NP (ADJP (ADJP yeni) (ADJP büyük))  (NP yasa))  (NP (ADJP karmaşık) (NP dil)) )  (VP (NP savaş) (VP bulan))  (. .)) " == tree->to_string());
    inputFile.close();
}

TEST_CASE("ParseTreeDrawableTest-testMaxDepth") {
    ParseTreeDrawable *tree0, *tree1, *tree2, *tree3, *tree4;
    ParseTreeDrawable *tree5, *tree6, *tree7, *tree8, *tree9;
    ifstream inputFile;
    inputFile.open("trees/0000.dev", ifstream::in);
    tree0 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0001.dev", ifstream::in);
    tree1 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0002.dev", ifstream::in);
    tree2 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0003.dev", ifstream::in);
    tree3 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0004.dev", ifstream::in);
    tree4 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0005.dev", ifstream::in);
    tree5 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0006.dev", ifstream::in);
    tree6 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0007.dev", ifstream::in);
    tree7 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0008.dev", ifstream::in);
    tree8 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    inputFile.open("trees/0009.dev", ifstream::in);
    tree9 = new ParseTreeDrawable(inputFile);
    inputFile.close();
    REQUIRE(5 == tree0->maxDepth());
    REQUIRE(5 == tree1->maxDepth());
    REQUIRE(5 == tree2->maxDepth());
    REQUIRE(5 == tree3->maxDepth());
    REQUIRE(6 == tree4->maxDepth());
    REQUIRE(3 == tree5->maxDepth());
    REQUIRE(4 == tree6->maxDepth());
    REQUIRE(6 == tree7->maxDepth());
    REQUIRE(5 == tree8->maxDepth());
    REQUIRE(6 == tree9->maxDepth());
}
