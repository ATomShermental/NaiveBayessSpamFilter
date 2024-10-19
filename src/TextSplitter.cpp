#include "TextSplitter.h"
#include <iostream>
#include <sstream>

TextSplitter::TextSplitter(std::string delims) : delims(delims) {}

bool TextSplitter::isDelim(char c) {
    for(int i = 0; i < delims.size();i++) {
        if(c == delims[i]) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> TextSplitter::split(const std::string& inputString) {
    std::vector<std::string> wordVector;
    std::stringstream stringStream(inputString);
    std::string word;
    char c;
    while (stringStream) {
        word.clear();
        while (!isDelim(c = stringStream.get()))
            word.push_back(c);
        if (c != EOF)
            stringStream.unget();

        wordVector.push_back(word);

        while (isDelim((c = stringStream.get())));
        if (c != EOF)
            stringStream.unget();
    }
    return wordVector;
}



