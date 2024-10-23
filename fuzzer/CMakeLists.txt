cmake_minimum_required(VERSION 3.29)
project(fuzzer C)

set(CMAKE_C_STANDARD 11)

add_executable(fuzzer
        main.c)
