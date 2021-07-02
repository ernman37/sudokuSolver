/*
*    Creator: Ernest M Duckworth IV
*    Date: Thu Jul  1 14:23:34 2021
*    For: Class Declaration for object: Sudoku
*    Description: 
*/
#ifndef Sudoku_hpp
#define Sudoku_hpp

#include <iostream>
#include <string>

class Sudoku{
  private:
    int table[9][9];
    long long counter = 0;

  public:
    Sudoku();
    void getInput();
    auto getTable() { return table; }
    void print();

    bool checkR(const int &, const int &);
    bool checkC(const int &, const int &);
    bool checkB(const int &, const int &, const int &);
    bool tryN(const int &, const int &, const int &);
    bool solve(int row, int col);

    long long getCounter();
    friend std::ostream& operator<<(std::ostream &, Sudoku &);
};

#endif
