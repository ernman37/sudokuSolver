/*
 *   Creator: Ernest M Duckworth IV
 *   Date: Thu Jul  1 14:42:11 2021
 *   For: 
 *   Description: 
*/
#include <iostream>
#include "Sudoku.hpp"

using namespace std;

int main(int argc, const char *argv[]){
    Sudoku s; 
    s.print();
    s.solve(0, 0);
    cout << "Solved: \n";
    s.print();
    cout << s.getCounter() << " iterations\n";


    return 0;
}
