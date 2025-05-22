#include <stdio.h>
#include <stdbool.h>
 
#define N 8 // Define the size of the chessboard
 
// Function to print the solution
void printSolution(int board[N][N]) {
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           printf("%d ", board[i][j]);
       }
       printf("\n");
   }
}
 
// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
   int i, j;
 
   // Check this row on the left side
   for (i = 0; i < col; i++)
       if (board[row][i])
           return false;
 
   // Check upper diagonal on the left side
   for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
       if (board[i][j])
           return false;
 
   // Check lower diagonal on the left side
   for (i = row, j = col; j >= 0 && i < N; i++, j--)
       if (board[i][j])
           return false;
 
   return true;
}
 
// Function to solve N Queens problem using backtracking
bool solveNQueens(int board[N][N], int col) {
   if (col >= N)
       return true;
 
   // Consider this column and try placing this queen in all rows
   for (int i = 0; i < N; i++) {
       if (isSafe(board, i, col)) {
           board[i][col] = 1; // Place the queen
 
           // Recur to place rest of the queens
           if (solveNQueens(board, col + 1))
               return true;
 
           // If placing queen in board[i][col] doesn't lead to a solution, remove the queen
           board[i][col] = 0;
       }
   }
 
   return false; // If queen can't be placed in any row in this column, return false
}
 
// Main function to solve the N Queens problem and print the solution
void solveNQueensProblem() {
   int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0} };
 
   if (solveNQueens(board, 0) == false) {
       printf("Solution does not exist");
       return;
   }
 
   printSolution(board);
}
 
int main() {
   solveNQueensProblem();
   return 0;
}