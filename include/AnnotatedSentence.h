//
// Created by Olcay Taner Yıldız on 2019-04-26.
//

#ifndef ANNOTATEDSENTENCE_ANNOTATEDSENTENCE_H
#define ANNOTATEDSENTENCE_ANNOTATEDSENTENCE_H

#include "Sentence.h"
#include "AnnotatedWord.h"
#include "FramesetList.h"
#include "Literal.h"
#include "WordNet.h"
#include "FsmMorphologicalAnalyzer.h"

class AnnotatedSentence : public Sentence {
public:
    AnnotatedSentence() = default;
    explicit AnnotatedSentence(istream& inputFile);
    explicit AnnotatedSentence(string sentence);
    bool containsPredicate();
    bool updateConnectedPredicate(string previousId, string currentId);
    vector<AnnotatedWord*> predicateCandidates(FramesetList& framesetList);
    string getPredicate(int index);
    void removeWord(int index);
    vector<Literal> constructLiterals(WordNet& wordNet, FsmMorphologicalAnalyzer& fsm, int wordIndex);
    vector<SynSet> constructSynSets(WordNet wordNet,FsmMorphologicalAnalyzer fsm, int wordIndex);
};


#endif //ANNOTATEDSENTENCE_ANNOTATEDSENTENCE_H
