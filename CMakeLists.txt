cmake_minimum_required(VERSION 3.19)
project(aoc2023)

set(CMAKE_CXX_STANDARD 14)

add_executable(aoc2023 main.cpp core/Utils.h core/Day.h days/Day01.cpp days/Day01.h days/Day02.cpp days/Day02.h days/Day03.cpp days/Day03.h)