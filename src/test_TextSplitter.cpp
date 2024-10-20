
#include <iostream>
#include <cassert>
#include <vector>
#include "TextSplitter.h"

TextSplitter splitter(";,:. \n\t");

void test_split() {
    std::vector<std::string> result = splitter.split("This,,,, is a test.");
    assert(result.size() == 4);
    assert(result[0] == "this");
    assert(result[1] == "is");
    assert(result[2] == "a");
    assert(result[3] == "test");
}

void test2_split() {
    std::vector<std::string> result = splitter.split("Buy, cheap watches now");
    assert(result.size() == 4);
    assert(result[0] == "buy");
    assert(result[1] == "cheap");
    assert(result[2] == "watches");
    assert(result[3] == "now");

}
int main() {
    test_split();
    test2_split();
    std::cout << "All tests passed!" << '\n';
    return 0;
}

