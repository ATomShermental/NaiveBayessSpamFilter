#ifndef TEXTSPLITTER_H
#define TEXTSPLITTER_H

#include <string>
#include<vector>

class TextSplitter {
private:
    const std::string delims;

    bool isDelim(char c);
public:
    TextSplitter(std::string delims);
    std::vector<std::string> split(const std::string& inputString);
};



#endif //TEXTSPLITTER_H
