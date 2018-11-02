cmake_minimum_required(VERSION 3.12)
project(Design_Pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(Design_Pattern
        Decoretor.cpp
        Observer.cpp
        Strategy.cpp
        Template_Method.cpp)
