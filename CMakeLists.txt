cmake_minimum_required(VERSION 3.29)
project(bayess_spam_filter)

set(CMAKE_CXX_STANDARD 20)

add_executable(spam_filter main.cpp)

add_executable(split_test test_TextSplitter.cpp TextSplitter.cpp TextSplitter.h)


