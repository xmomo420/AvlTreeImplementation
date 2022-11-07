cmake_minimum_required(VERSION 3.23)
project(inf3105_tp2_a22)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(inf3105_tp2_a22
        01_arbreAVL.cpp
        01_librairie.cpp
        01_livre.cpp
        02_arbreAVL.cpp
        02_librairie.cpp
        02_livre.cpp
        03_arbreAVL.cpp
        03_librairie.cpp
        03_livre.cpp
        04_arbreAVL.cpp
        05_arbreAVL.cpp
        06_arbreAVL.cpp
        07_arbreAVL.cpp
        08_arbreAVL.cpp
        09_arbreAVL.cpp
        arbreavl.h
        librairie.h
        livre.h
        pile.h)
