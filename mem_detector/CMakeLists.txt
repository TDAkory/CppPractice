cmake_minimum_required(VERSION 3.17)
project(mem_detector)

set(CMAKE_CXX_STANDARD 17)

add_executable(mem_detector main.cpp mem_detector.h mem_detector.cpp)