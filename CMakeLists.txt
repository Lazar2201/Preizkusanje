cmake_minimum_required(VERSION 3.14)
project(BF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
        BellmanFord
        main.cpp
        BellmanFord.cpp
        BellmanFord.h
)
