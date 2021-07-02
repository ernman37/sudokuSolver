/*
*    Creator: Ernest M Duckworth IV
*    Date: Thu Jul  1 14:23:34 2021
*    For: Class Implementation for object: Sudoku
*    Description: 
*/

#include <iostream>
#include "Sudoku.hpp"
#include <string>

using namespace std;

Sudoku::Sudoku(){ getInput(); }

bool Sudoku::getInput(){
    for (int i = 0; i < 9; i++){
        cout << "Input Row #" << i+1 << '\n';
        string line = "";
        while (line.length() != 9) getline(cin, line);
        for (int j = 0; j < 9; j++){
            int num = ((int)line[j]) - 48;
            if(num > 9 || num < 0){
               i--;
               break;
            }
            table[i][j] = num;
        }
    }
    return true;
}

void Sudoku::print(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
           cout << table[i][j] << "  ";
        cout << '\n';
    }
}



bool Sudoku::checkR(const int &c, const int &n){
    for(int i = 0; i < 9; i++)
       if(table[i][c] == n) return false;
    return true;

}

bool Sudoku::checkC(const int &r, const int &n){
    for(int i = 0; i < 9; i++)
       if(table[r][i] == n) return false;
    return true;
}

bool Sudoku::checkB(const int &r, const int &c, const int &n){
    int br = r - (r % 3),
        bc = c - (c % 3);

    for(int i = 0; i < 3; i++)
       for(int j = 0; j < 3; j++)
          if(table[i + br][j + bc] == n) return false;
    return true;
}

bool Sudoku::tryN(const int &r, const int &c, const int &n){
    return (checkR(c,n) && checkC(r,n) && checkB(r,c,n));
}

bool Sudoku::solve(int row, int col){
    //End of the table has been reached
    if(row == 8 && col == 9) return true;
    //Iterate to next row
    if(col == 9){
       row++;
       col = 0;
    }
    //Skips already solved slots
    if(table[row][col] != 0) return solve(row, ++col);
    //Trys every number in a loop and removes bad ones
    for(int num = 1; num < 10; num++){
       if(tryN(row, col, num)){
          counter++;
          table[row][col] = num;
          if(solve(row, col+1))
             return true;
       }
       //resets the row
       table[row][col] = 0;
    }
    return false;
}


long long Sudoku::getCounter(){
   return counter;
}

