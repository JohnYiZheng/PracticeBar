cmake_minimum_required(VERSION 3.15.0)

project(fmt_test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

list(APPEND CMAKE_PREFIX_PATH "/home/yi/Projects/PracticeBar/PracticeBar/3-15/fmt-8.1.1/install")

find_package(fmt)

add_executable(fmt_test main.cpp)
target_link_libraries(fmt_test fmt::fmt)