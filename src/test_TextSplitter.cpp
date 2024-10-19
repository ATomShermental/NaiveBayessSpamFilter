#define TEST_MODE

#include <iostream>
#include <cassert>
#include "TextSplitter.h"

void test_split() {
    TextSplitter splitter(";,:. \n\t");

    std::vector<std::string> result = splitter.split("This,,,, is a test.");
    assert(result.size() == 4);
    assert(result[0] == "This");
    assert(result[1] == "is");
    assert(result[2] == "a");
    assert(result[3] == "test");
}

int main() {
    test_split();
    std::cout << "All tests passed!" << '\n';
    return 0;
}

