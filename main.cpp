/*
 *   Creator: Ernest M Duckworth IV
 *   Date: Thu Jul  1 14:42:11 2021
 *   For: 
 *   Description: 
*/
#include <iostream>
#include <chrono>
#include "Sudoku.hpp"

using namespace std;
using namespace std::chrono;

int main(int argc, const char *argv[]){
    auto start = steady_clock::now();
    Sudoku s; 
    auto elapsed = steady_clock::now() - start;
    auto ms = duration_cast<milliseconds>(elapsed);
    cout << s.getCounter() << " iterations\n";
    cout << "That took " << ms.count() << "ms\n";
    return 0;
}
