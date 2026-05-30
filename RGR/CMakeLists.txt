cmake_minimum_required(VERSION 3.10)

project(AnagrammProject C)

set(CMAKE_C_STANDART 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(anagram_prog main.c anagramm.c anagramm.h)