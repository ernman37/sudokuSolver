/*
*    Creator: Ernest M Duckworth IV
*    Date: Thu Jul  1 14:23:34 2021
*    For: Class Implementation for object: Sudoku
*    Description: 
*/

#include <iostream>
#include "Sudoku.hpp"
#include <string>
#include <chrono>

//Includes namespaces and defines new type of float seconds
using namespace std;
using namespace std::chrono;
using floatsec = duration<double, ratio<1,1>>;


//Constructor which auto solves the puzzle
Sudoku::Sudoku(){ 
    getInput(); 

    auto start = steady_clock::now();
    bool ran = solve();
    auto ms = duration_cast<milliseconds>(steady_clock::now() - start);
    floatsec s = ms;

    if(ran) cout << "Solved: \n" << *this;
    else cout << "Unsolvable Puzzel\n";

    cout << counter << " iterations in " << s.count() << " seconds or " << ms.count() << " milliseconds\n";
}

//Gets input from user
//Format in solid numbers no spaces 
//0's represent unmarked spot
void Sudoku::getInput(){
    //loop for all 9 rows
    for (int i = 0; i < 9; i++){
        cout << "Input Row #" << i+1 << '\n';
        string line = "";

        while (line.length() != 9)
            getline(cin, line);

        //loop for all 9 colums
        for (int j = 0; j < 9; j++){
            int num = ((int)line[j]) - 48;
            if(num > 9 || num < 0){
               i--;
               break;
            }
            table[i][j] = num;
        }
    }
    cout << "Puzzel Entered: \n" << *this;
}


//Checks every Row for the c colum for the n number
bool Sudoku::checkR(const int &c, const int &n){
    for(int i = 0; i < 9; i++)
       if(table[i][c] == n) return false;
    return true;
}


//Checks every colum in the r row for the n number
bool Sudoku::checkC(const int &r, const int &n){
    for(int i = 0; i < 9; i++)
       if(table[r][i] == n) return false;
    return true;
}


//Checks corresponding box for r & c position for n number
bool Sudoku::checkB(const int &r, const int &c, const int &n){
    int br = r - (r % 3),
        bc = c - (c % 3);

    for(int i = 0; i < 3; i++)
       for(int j = 0; j < 3; j++)
          if(table[i + br][j + bc] == n) return false;
    return true;
}


//Checks if n fits requirements for certain spot
bool Sudoku::tryN(const int &r, const int &c, const int &n){
    return (checkR(c,n) && checkC(r,n) && checkB(r,c,n));
}


//Solves the table
bool Sudoku::solve(int row, int col){
    //End of the table has been reached
    if(row == 8 && col == 9) return true;

    //Iterate to next row
    if(col == 9){
       row++;
       col = 0;
    }

    //Skips already solved slots
    if(table[row][col] != 0) return solve(row, col+1); 

    //Trys every number in a recursive loop
    for(int num = 1; num < 10; num++){
       if(tryN(row, col, num)){
          counter++; 
          table[row][col] = num;
          if(solve(row, col+1)) return true;
       }
       table[row][col] = 0; //Resets if passed number fails
    }
    return false;
}


//Returns iteration counter
long long Sudoku::getCounter(){
   return counter;
}


//Outputs the table
ostream& operator<<(ostream &os, Sudoku &copy){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
           os << copy.getTable()[i][j] << "  ";
        os << '\n';
    }
    return os;
}

