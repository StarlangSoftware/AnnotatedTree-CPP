//
// Created by Olcay Taner Yıldız on 7.10.2018.
//

#ifndef PROPBANK_FRAMESETARGUMENT_H
#define PROPBANK_FRAMESETARGUMENT_H
#include <string>

using namespace std;

class FramesetArgument {
private:
    string argumentType;
    string definition;
public:
    FramesetArgument(string argumentType, string definition);
    string getArgumentType();
    string getDefinition();
    void setDefinition(string definition);
    string to_string();
};


#endif //PROPBANK_FRAMESETARGUMENT_H
