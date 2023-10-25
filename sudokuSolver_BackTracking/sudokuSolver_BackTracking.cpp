
#include <iostream>
#include<vector>

using namespace std;

void printSudokuBoard(vector<vector<int>> &sudokuBoard) {
    for (int row = 0; row < sudokuBoard.size(); row++) {
        for (int col = 0; col < sudokuBoard.size(); col++) {
            cout << sudokuBoard[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, int val, vector<vector<int>>& sudokuBoard)
{
    
    for (int i = 0; i < sudokuBoard.size(); i++) {
        // check whether the entered value is present is row or col
        if (sudokuBoard[row][i] == val && sudokuBoard[i][col] == val) return false;

        //check in 3x3 matrix
        if (sudokuBoard[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}

bool sudoSolver(vector<vector<int>>& sudokuBoard)
{
    int n = sudokuBoard.size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //if cell is empty
            if (sudokuBoard[row][col] == 0)
            {
                //try all possible value from 1- 9
                for (int val = 1; val <= 9; val++)
                {
                    //check is safe to add at that position
                    if (isSafe(row, col, val, sudokuBoard))
                    {
                        sudokuBoard[row][col] = val;

                        //recursive call
                        //new value is added in the board, call the function again to check whether it will fit for others well
                        if (sudoSolver(sudokuBoard)) return true; //fits
                        else sudokuBoard[row][col] = 0; //backtracking
                    }

                }// for val end
            }
        }// for col end
    }// for row end
}


int main()
{
    cout << "<----------Sudoku Solver----------> ";
    cout << endl << endl;
    
    vector<vector<int>> sudokuBoard = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Sudoku Board: " << endl << endl;
    printSudokuBoard(sudokuBoard);

    cout << endl << endl;

    cout << "Solved Sudoku Board: " << endl << endl;

    if (sudoSolver(sudokuBoard)) printSudokuBoard(sudokuBoard);
    else cout << "No solution exists." << endl;
    

}

