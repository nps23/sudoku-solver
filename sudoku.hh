#ifndef SUDOKU_HH
#define SUDOKU_HH

#include <vector>

class SudokuPuzzle {
  std::vector<std::vector<int>> board;

public:
  SudokuPuzzle(const int size);
  SudokuPuzzle(const std::vector<std::vector<int>> &_board);
  void operator()();
  void PrintBoard() const;

private:
  bool validRow(int data, int rowIndex) const;
  bool validColumn(int data, int columnIndex) const;
  bool validSquare(int rowIndex, int columnIndex, int value) const;
  bool isValid(int row, int col, int data) const;
  // if this is going to be the recusrive algorithm, we will need to use a
  // boolean (or some conditional) return type
  bool insert(int rowIndex, int columnIndex);
  bool done() const;
};

#endif