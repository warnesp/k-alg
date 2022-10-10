cmake_minimum_required (VERSION 3.24)

project(KahnAlg VERSION 1.0)

add_library(KAlg
    src/kalg.cpp
    )

set_property(TARGET KAlg PROPERTY CXX_STANDARD 17)

target_include_directories(KAlg 
    PUBLIC
    include
    )

add_subdirectory(UnitTests)

include(CTest)

