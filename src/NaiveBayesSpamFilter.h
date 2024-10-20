#ifndef NAIVEBAYESSSPAMFILTER_H
#define NAIVEBAYESSSPAMFILTER_H
#include <set>
#include <map>
class NaiveBayesSpamFilter {
private:
    std::set<std::string> vocabulary;
    std::map<std::string, int> spamWordsCount;
    std::map<std::string,int> hamWordsCount;
    int numSpamWords;
    int numHamWords;
    int numSpamDocs;
    int numHamDocs;
public:
    NaiveBayesSpamFilter();
    void train(const std::vector<std::pair<std::string,bool>>& data);

    bool predict(const std::string& text);
};

#endif