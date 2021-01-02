#include <iostream>
#define N 9 // 9x9 sudoku puzzle
int grid[N][N] = {
   {0, 0, 0, 6, 0, 0, 4, 0, 0},
   {7, 0, 0, 0, 0, 3, 6, 0, 0},
   {0, 0, 0, 0, 9, 1, 0, 8, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 5, 0, 1, 8, 0, 0, 0, 3},
   {0, 0, 0, 3, 0, 6, 0, 4, 5},
   {0, 4, 0, 2, 0, 0, 0, 6, 0},
   {9, 0, 3, 0, 0, 0, 0, 0, 0},
   {0, 2, 0, 0, 0, 0, 1, 0, 0}
};

bool isPresentInCol(int col, int num){   
    // Checks if num is in col
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool isPresentInRow(int row, int num){   
    // Checks if num is in row
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool isPresentInSquare(int squareStartRow, int squareStartCol, int num){
    // Check if num is in 3x3 square
    for (int row = 0; row < 3; row++)
        for (int col = 0; col <3; col++)
            if (grid[row+squareStartRow][col+squareStartCol] == num)
                return true;
    return false;
}

void sudokuGrid(){ 
    // Print solved Sudoku grid
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 3 || col == 6)
                std::cout << " | ";
            std::cout << grid[row][col] << " ";
            }
        if(row == 2 || row == 5){
            std::cout << std::endl;
            for(int i = 0; i < N; i++)
                std::cout << "---";
        }
    std::cout << std::endl;
    }
}

bool findEmptyLocation(int &row, int &col){ 
    // Get empty location and update row and col
    for(row = 0; row < N; row++)
        for(col = 0; col < N; col++)
            if (grid[row][col] == 0) // Empty location
                return true;
    return false;
}

bool isValidLocation(int row, int col, int num){
    // Item is not found in col, row or 3x3 square
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInSquare(row - row%3, col - col%3, num);
}

bool solveSudoku(){
    int row, col;
    if (!findEmptyLocation(row, col))
        return true; // All locations are filled
    for (int num = 1; num <= 9; num++){
        if (isValidLocation(row, col, num)){
            // Checks if number is valid. If it is valid, puts number in location
            grid[row][col] = num;
            if (solveSudoku())
                // Recurion for rest of the grid
                return true;
            grid[row][col] = 0;
            // If conditions are not satisfied, turn space to 0
        }
    }
    return false;
}

int main(){
    if (solveSudoku() == true)
        sudokuGrid();
    else
    {
        std::cout << "There are no valid solutions.";
    }
    

}