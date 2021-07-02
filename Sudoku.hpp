/*
*    Creator: Ernest M Duckworth IV
*    Date: Thu Jul  1 14:23:34 2021
*    Class Declaration for object: Sudoku
*    Description: The body of an object that solves sudoku puzzles 
*/
#ifndef Sudoku_hpp
#define Sudoku_hpp

#include <iostream>

class Sudoku{
  private:
    //Variables
    int table[9][9];
    long long counter = 0;

  public:
    //Helper and initialization functions
    Sudoku();
    void getInput();
    auto getTable() { return table; }
    long long getCounter();
    friend std::ostream& operator<<(std::ostream &, Sudoku &);
    
    //Testing functions
    bool checkR(const int &, const int &);
    bool checkC(const int &, const int &);
    bool checkB(const int &, const int &, const int &);
    bool tryN(const int &, const int &, const int &);
    bool solve(int row=0, int col=0);
};

#endif
