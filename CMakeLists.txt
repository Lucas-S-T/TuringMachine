cmake_minimum_required(VERSION 3.17)
project(TuringMachine C)

set(CMAKE_C_STANDARD 99)

add_executable(TuringMachine main.c machine.c machine.h instructionSet.c instructionSet.h)