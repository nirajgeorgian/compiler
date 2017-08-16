cmake_minimum_required(VERSION 3.8)
project(compiler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c lex.h)
add_executable(compiler ${SOURCE_FILES})