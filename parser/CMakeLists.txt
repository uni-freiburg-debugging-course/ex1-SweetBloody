cmake_minimum_required(VERSION 3.29)
project(parser C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(parser
        src/main.c
        src/cdio.c
        src/file_process.c
        src/process.c
        inc/cdio.h
        inc/file_process.h
        inc/process.h
        inc/struct.h
        src/struct.c)
