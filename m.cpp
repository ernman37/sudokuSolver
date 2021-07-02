#include <iostream>
 
using namespace std;
 
// N is the size of the 2D matrix   N*N
#define N 9

/* A utility function to print grid */
void print(int arr[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

bool checkC(int table[N][N], int r, int c, int n){
    for (int i = 0; i <= 8; i++)
        if (table[r][i] == n)
            return false;
    return true;
}

bool checkR(int table[N][N], int r, int c, int n){
    for (int i = 0; i <= 8; i++)
        if (table[i][c] == n)
            return false;
    return true;
}

bool checkB(int table[N][N], int r, int c, int n){
    int br = r - (r % 3),
        bc = c - (c % 3);
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (table[i + br][j + bc] == n)
                return false;
    return true;
}

bool checkN(int t[N][N], int r, int c, int n){
    return (checkB(t,r,c,n) && checkC(t,r,c,n) && checkR(t,r,c,n)); 
}
 
bool solveSuduko(int table[N][N], int row, int col){
    if (row == N-1 && col == N) return true;
 
    if (col == N) {
        row++;
        col = 0;
    }
   
    if (table[row][col] != 0) return solveSuduko(table, row, ++col);
 
    for (int num = 1; num <= N; num++){
        if (checkN(table, row, col, num)){
            table[row][col] = num;
            if (solveSuduko(table, row, col + 1))
                return true;
        }
        table[row][col] = 0;
    }
    return false;
}
 
int main(){
    // 0 means unassigned cells
    int grid[N][N] = { { 8, 0, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 0, 3, 6, 0, 0, 0, 0, 0 },
                       { 0, 7, 0, 0, 9, 0, 2, 0, 0 },
                       { 0, 5, 0, 0, 0, 7, 0, 0, 0 },
                       { 0, 0, 0, 0, 4, 5, 7, 0, 0 },
                       { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
                       { 0, 0, 1, 0, 0, 0, 0, 6, 8 },
                       { 0, 0, 8, 5, 0, 0, 0, 1, 0 },
                       { 0, 9, 0, 0, 0, 0, 4, 0, 0 } };

    cout << "Unsolved grid (0's represent open slots)\n";
    print(grid);
    if (solveSuduko(grid, 0, 0)){
        cout << "Solved Grid: \n";
        print(grid);
    }
    else
        cout << "no solution  exists " << endl;
 
    return 0;
}
