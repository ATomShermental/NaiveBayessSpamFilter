#include <iostream>
#include "NaiveBayesSpamFilter.h"
#include "TextSplitter.h"
//
// void printVector(const std::vector<std::string>& data) {
//     for(auto const& sample : data) {
//         std::cout << sample << ' ';
//     }
//     std::cout << '\n';
// }
TextSplitter splitter(";,:. \n\t");

NaiveBayesSpamFilter::NaiveBayesSpamFilter() {
     numSpamWords = 0;
    numHamWords = 0;
    numSpamDocs = 0;
    numHamDocs = 0;
}

void NaiveBayesSpamFilter::train(const std::vector<std::pair<std::string,bool>>& data) {
    for(const auto& sample : data) {
        std::string text = sample.first;
        bool isSpam = sample.second;
        std::vector<std::string> words = splitter.split(text);
        if(isSpam) {
            numSpamDocs++;
            for(auto const& word : words) {
                numSpamWords++;
                vocabulary.insert(word);
                spamWordsCount[word]++;
            }
        } else {
            numHamDocs++;
            for(auto const& word : words) {
                vocabulary.insert(word);
                numHamWords++;
                hamWordsCount[word]++;
            }
        }
    }
}

bool NaiveBayesSpamFilter::predict(const std::string& text) {
    double spamLogProb = log(numSpamDocs/static_cast<double>(numSpamDocs+numHamDocs));

    double hamLogProb = log(numHamDocs/static_cast<double>(numSpamDocs+numHamDocs));
    std::vector<std::string> words = splitter.split(text);

    for(auto const& word : words) {
        spamLogProb += log((spamWordsCount[word] + 1)/static_cast<double>(vocabulary.size()+numSpamWords));

        hamLogProb += log((hamWordsCount[word]+1)/static_cast<double>(vocabulary.size()+numHamWords));
    }

    return spamLogProb > hamLogProb;
}