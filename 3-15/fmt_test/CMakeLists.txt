cmake_minimum_required(VERSION 3.15.0)

project(fmt_test)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

add_executable(fmt_test main.cpp)