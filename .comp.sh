#!/bin/bash

g++ -std=c++17 Sudoku.hpp Sudoku.cpp main.cpp
mv a.out solver
rm Sudoku.hpp.gch
