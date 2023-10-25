# SudokuWizard
### A command-line application developed using C++ that can solve Sudoku puzzles using the Backtracking technique. The program takes the unsolved grid as input and provides the solved grid as output.

# Implementation:
- Find an empty cell (cell with a value of 0).
- Try placing a number (1 to 9) in that cell.
- Check if it's a valid move.
- If valid, move on to the next empty cell.
- If not valid, backtrack and try the next number.
- Continue this process until the grid is filled

# IDE:
## Visual Studio

# Data Structure:
- vector

# Matrix
![unsolved](https://github.com/AmreenKhan1003/SudokuWizard/blob/main/unsolved.PNG)

# Input
- Provide n x n unsolved matrix.
- vector<vector<int>>

# Output
- Provide n x n solved matrix.
- vector<vector<int>>

![unsolved](https://github.com/AmreenKhan1003/SudokuWizard/blob/main/solved.PNG)

