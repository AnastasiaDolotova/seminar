cmake_minimum_required(VERSION 3.20)
project(seminar)

set(CMAKE_CXX_STANDARD 14)

add_executable(seminar main.cpp cmake-build-debug/Matrix.cpp cmake-build-debug/Matrix.h)
