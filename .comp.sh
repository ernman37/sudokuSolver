#!/bin/bash

g++ -std=c++17 -c Sudoku.hpp Sudoku.cpp
g++ -std=c++17 -o solver Sudoku.o main.cpp
rm Sudoku.hpp.*
