#include "nqueenssolution.h"
#include <iostream>

nQueensSolution::nQueensSolution(int columns)
{
    assert (columns > 0);
    _sol = new int[columns]; //Declare a int array to hold the solution
                            //The length of the ventor corresponds to the number of columns on the board
                            //The value in each cell represents the row position of the queen in that column
                            //For example, sol[k] = r means that the queen in column k is in row r
    _columnCount = columns;

    //Initialise all cells to -1:
    for (int i = 0; i < columns; i++)
    {
        _sol[i] = -100;
    }
}

void nQueensSolution::setValue(int row, int col)
{
    _sol[col] = row;
}

int nQueensSolution::getValue(int col)
{
    return _sol[col];
}

int nQueensSolution::getColumnCount()
{
    return _columnCount;
}

void nQueensSolution::printSolution()
{
    std::cout << "Solution:" << "\n";
    for (int c = 0; c < _columnCount; c++)
    {
        std::cout << _sol[c] << " ";
    }
    std::cout << "\n";
}
