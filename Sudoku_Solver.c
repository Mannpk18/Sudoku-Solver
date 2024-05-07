#include <stdio.h>
#include <stdbool.h>

int count = 0; 

#define N 9


void ViewSudokuBoard(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}


bool isValidPosition(int grid[N][N], int row, int col, int num) {
    
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

   
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}


bool solveProblem(int grid[N][N]) {
    count++;

    
    int row, col;
    bool foundEmptyCell = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                foundEmptyCell = true;
                break;
            }
        }
        if (foundEmptyCell) {
            break;
        }
    }

    
    if (!foundEmptyCell) {
        return true;
    }

    
    for (int num = 1; num <= 9; num++) {
        if (isValidPosition(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveProblem(grid)) {
                return true;
            }
            grid[row][col] = 0; 
        }
    }

    return false; 
}

int main() {
    int grid[N][N] = {
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 3},
        {0, 7, 4, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 2},
        {0, 8, 0, 0, 4, 0, 0, 1, 0},
        {6, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 7, 8, 0},
        {5, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0}
    };

    printf("The input Sudoku puzzle:\n");
    ViewSudokuBoard(grid);

    if (solveProblem(grid)) {
        printf("Solution is found after %d iterations:\n", count);
        ViewSudokuBoard(grid);
    } else {
        printf("No solutions exist.\n");
    }

    return 0;
}
