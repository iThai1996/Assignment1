cmake_minimum_required(VERSION 3.8)
project(Assignment1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        board_generator.c
        board_generator.h
        boggle.c
        dictionary.c
        dictionary.h
        scoreboard.c
        scoreboard.h
        word_checker.c
        word_checker.h)

add_executable(Assignment1 ${SOURCE_FILES})