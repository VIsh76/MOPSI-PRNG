cmake_minimum_required(VERSION 3.6)
project(Projet_MOPSI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LCG.cpp LCG.h ziggurat.cpp ziggurat.h)
add_executable(Projet_MOPSI ${SOURCE_FILES})