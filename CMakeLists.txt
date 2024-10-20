cmake_minimum_required(VERSION 3.29)
project(bayess_spam_filter)

set(CMAKE_CXX_STANDARD 20)

add_executable(spam_filter src/NaiveBayessSpamFilter.cpp src/NaiveBayesSpamFilter.h src/test_NaiveBayessSpamFilter.cpp src/TextSplitter.cpp src/TextSplitter.h)

add_executable(split_test src/test_TextSplitter.cpp src/TextSplitter.cpp src/TextSplitter.h)


