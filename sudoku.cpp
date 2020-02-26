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
    int row_sweep = rowIndex % 3;
    int col_sweep = columIndex %3;

    int row_bounds[2] = {0, 0};
    int col_bounds[2] = {0, 0};

    switch(row_sweep) { //set bounds for the row position
        case 0: //we are at the start of a grid
            row_bounds[0] = rowIndex;
            row_bounds[1] = rowIndex + 2;
            break;
        case 1: //we are the middle of a grid
            row_bounds[0] = rowIndex - 1;
            row_bounds[1] = rowIndex + 1;
            break;
        case 2: //we are at the edge of a grid
            row_bounds[0] = rowIndex - 2;
            row_bounds[1] = rowIndex;
            break;
    }

    switch(col_sweep) { //set bounds for the col. position
        case 0: //we are at the start of a grid
            col_bounds[0] = columIndex;
            col_bounds[1] = columIndex + 2;
            break;
        case 1: //we are in the middle of a grid
            col_bounds[0] = columIndex - 1;
            col_bounds[1] = columIndex + 1;
            break;
        case 2: //we are at the edge of a grid
            col_bounds[0] = columIndex - 2;
            col_bounds[1] = columIndex;
            break;
    }

    for (int i = row_bounds[0]; i <= row_bounds[1]; ++i) {
        for (int j = col_bounds[0]; j <= col_bounds[1]; ++j) {
            if (board[i][j] == value) {
                return false;
            }
        }
    }

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