#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H
#include "stype.h"

const int NINE = 9;
const int SIX = 6;
const int THREE = 3;
const int ONE = 1;

class SudokuSolver
{
public:
    SudokuSolver();
    bool findSolution(int row, int col);
    int value(int row, int col) const;
    void setValue(int row, int col, int value);
    void setValueFixed(int row, int col, int value);
    void print();


private:
    sType _sol[NINE][NINE];
    bool numberIsValid(int number);
    bool digitIsValid(int digit);
    bool rowIsValid(int row);
    bool colIsValid(int col);
    bool sameDigitInRow(int row, int col, int digit);
    bool sameDigitInCol(int row, int col, int digit);
    bool sameDigitInSubGrid(int row, int col, int digit);
    bool sameDigitFound(int row, int col, int digit);

};

#endif // SUDOKUSOLVER_H
