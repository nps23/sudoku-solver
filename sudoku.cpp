#include <iostream>
#include "sudoku.hh"

constexpr static int BOARD_SIZE = 9;

//default constructor resizes the board accordingly
SudokuPuzzle::SudokuPuzzle(const int _size) {
    board.resize(BOARD_SIZE);
    for (auto column : board) {
        column.resize(BOARD_SIZE);
    }
}

//constructor taking vector of vector of ints and resizing accordingly
SudokuPuzzle::SudokuPuzzle(const std::vector<std::vector<int>>& _board) : board(_board) {};

void SudokuPuzzle::PrintBoard() const {
    for (auto& row  : board) {
        for (auto& column : row) {
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }
}

bool SudokuPuzzle::validRow(int data, int rowIndex) const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[rowIndex][i] == data) {
            return false;
        }
    }

    return true;
}

bool SudokuPuzzle::validColumn(int data, int columnIndex) const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][columnIndex] == data) {
            return false;
        }
    }

    return true;
}

bool SudokuPuzzle::validSquare(int rowIndex, int columIndex, int value) const{
    return true;
}

bool SudokuPuzzle::done() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    std::cout << "deciding to be done with board state: " << std::endl;
    PrintBoard();
    return true;
}

bool SudokuPuzzle::isValid(int row, int col, int data) const {
    return (validRow(data, row) && validColumn(data, col) && validSquare(row, col, data));
}

bool SudokuPuzzle::insert(int rowIndex, int columnIndex) {
    //base case - we are finished
    if (done()) { 
        return true;
    }
    //make sure we don't go out of bounds. Shouldn't need to consider the column case
    if (columnIndex >= BOARD_SIZE) {
        return (insert(rowIndex + 1, 0));
    }

    //we've considered all the columns. Shouldn't need this
    // if (columnIndex >= BOARD_SIZE) {
    //     return true;
    // }

    if (board[rowIndex][columnIndex] == 0) {
        for (int i = 1; i <= 9; ++i) {
            int old = board[rowIndex][columnIndex];
            // board[rowIndex][columnIndex] = i;
            if (isValid(rowIndex, columnIndex, i)) {
                board[rowIndex][columnIndex] = i;

                if (insert(rowIndex, columnIndex +1))
                    return true; //we are done
            
                board[rowIndex][columnIndex] = old; //backtracking here
            }

        }

        return false;
    }

    return (insert(rowIndex, columnIndex + 1)); //should be ok, since we are still exiting when done
}

void SudokuPuzzle::operator()() {
    insert(0, 0);

    return;
}