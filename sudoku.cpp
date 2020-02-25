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

bool SudokuPuzzle::validRow(int rowIndex, int columnIndex) const {

}

bool SudokuPuzzle::validColumn(int rowIndex, int columnIndex) const {

}

bool SudokuPuzzle::validSquare(int rowIndex, int columIndex, int value) const{

}

bool SudokuPuzzle::done() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void SudokuPuzzle::insert(int rowIndex, int columnIndex) {
    //base case - we are finished
    if (done()) { 
        return;
    }
    //make sure we don't go out of bounds. Shouldn't need to consider the column case
    if (rowIndex >= BOARD_SIZE) {
        return (insert(0, columnIndex +1));
    }

    for (int i = 1; i <= 9; ++i) {
        board[rowIndex][columnIndex] = i;
        //if (validRow)
    }

}