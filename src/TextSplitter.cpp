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
    std::string word;
    char c;

    std::istringstream stringStream(inputString);

    while (stringStream.get(c)) {
        c = std::tolower(static_cast<unsigned char>(c));
        if (!isDelim(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                wordVector.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        wordVector.push_back(word);
    }

    return wordVector;
}



