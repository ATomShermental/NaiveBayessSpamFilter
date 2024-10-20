
#include <iostream>
#include <cassert>
#include "NaiveBayesSpamFilter.h"

void test_filter() {
    std::vector<std::pair<std::string, bool>> trainingData = {
        {"Buy cheap watches now", true},
        {"Hello friend, how are you", false},
        {"Win a million dollars", true},
        {"Lets catch up later", false},
        {"Limited time offer", true},
        {"Meeting tomorrow at", false}
    };

    NaiveBayesSpamFilter filter;
    filter.train(trainingData);

    std::string newEmail = "buy a cheap offer later tomorrow";
    bool isSpam = filter.predict(newEmail);
    assert(isSpam == true);
}

int main() {
    test_filter();
    std::cout << "All tests passed!" << '\n';
    return 0;
}

