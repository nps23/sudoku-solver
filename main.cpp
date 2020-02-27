#include <iostream>
#include "sudoku.hh"

int main()
{
    std::vector<std::vector<int>> board = {
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

    std::cout << board.size() << std::endl;
    
    SudokuPuzzle puzzle(board);
    
    std::cout << "Sudoku puzzle board:" << std::endl;
    puzzle.PrintBoard();

    puzzle();
    std::cout << "Solved puzzle:" << std::endl;
    puzzle.PrintBoard();

    std::vector<std::vector<int>> board2 = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    std::cout << "Puzzle 2: " << std::endl;
    SudokuPuzzle puzzle2(board2);
    puzzle2.PrintBoard();

    puzzle2();
    std::cout << "Solution to second puzzle:" << std::endl;
    puzzle2.PrintBoard();

    std::vector<std::vector<int>> board3 = {
        {0, 0, 6, 4, 8, 1, 3, 0, 0},
        {0, 2, 0, 0, 0, 0, 4, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 9},
        {8, 0, 0, 0, 9, 0, 0, 0, 4},
        {6, 0, 0, 3, 4, 2, 0, 0, 1},
        {5, 0, 0, 0, 6, 0, 0, 0, 2},
        {3, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 9, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 5, 7, 1, 6, 2, 0, 0}
    };

    SudokuPuzzle puzzle3(board3);
    std::cout << "Puzzle 3 is" << std::endl;
    puzzle3.PrintBoard();

    puzzle3();
    std::cout << "Solution to puzzle 3 is " << std::endl;
    puzzle3.PrintBoard(); 

    return 0;

}