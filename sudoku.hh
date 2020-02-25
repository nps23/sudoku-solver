#ifndef SUDOKU_HH
#define SUDOKU_HH

#include <vector>

class SudokuPuzzle
{
    std::vector<std::vector<int>> board;
public:
    SudokuPuzzle(const int size);
    SudokuPuzzle(const std::vector<std::vector<int>>& _board);
    void operator()();
    void PrintBoard() const;
private:
    bool validRow(int rowIndex, int value) const;
    bool validColumn(int rowIndex, int value) const;
    bool validSquare(int rowIndex, int columnIndex, int value) const;
    void insert(int rowIndex, int columnIndex);
    bool done() const;
};





#endif