#include "sudokusolver.h"
#include <iostream>

SudokuSolver::SudokuSolver()
{
    for (int r = 0; r < NINE; r++)
    {
        for (int c = 0; c < NINE; c++)
        {
            _sol[r][c]  = sType();
        }
    }
}

bool SudokuSolver::findSolution(int row, int col)
{
    if (_sol[row][col].state() != State::fixed)
    {
        for (int digit = ONE; digit < NINE + 1; digit++)
        {
            if (!sameDigitFound(row, col, digit))
            {
                _sol[row][col].setValue(digit);
                if ((row == NINE - 1) && (col == NINE - 1)) //Last cell
                {
                    return true;
                }
                else if (col == NINE - 1) //End of row
                {
                    if (findSolution(row + 1, 0)) //Start new row
                    {
                        return true;
                    }
                }
                else
                {
                    if (findSolution(row, col +1)) //Same row, next col
                    {
                        return true;
                    }
                }
            }
        }
        return false; //Could not find a valid digit
    }
    else
    {
        if ((row == NINE - 1) && (col == NINE - 1)) //Last cell
        {
            return true;
        }
        else if (col == NINE - 1) //End of row
        {
            if (findSolution(row + 1, 0)) //Start new row
            {
                return true;
            }
        }
        else
        {
            if (findSolution(row, col +1)) //Same row, next col
            {
                return true;
            }
        }
    };
}

int SudokuSolver::value(int row, int col) const
{
    return _sol[row][col].value();
}

void SudokuSolver::setValue(int row, int col, int value)
{
    _sol[row][col].setValue(value);
}

void SudokuSolver::setValueFixed(int row, int col, int value)
{
    _sol[row][col].setValueFixed(value);
}

void SudokuSolver::print()
{
    for (int r = 0; r < NINE; r++)
    {
        for (int c = 0; c < NINE; c++)
        {
            std::cout << _sol[r][c].value() << " ";
        }
        std::cout << "\n";
    }
}

bool SudokuSolver::numberIsValid(int number)
{
    if ((number > 0) && (number < NINE + 1))
    {
        return true;
    }
    else return false;
}

bool SudokuSolver::digitIsValid(int digit)
{
    return numberIsValid(digit);
}

bool SudokuSolver::rowIsValid(int row)
{
    return numberIsValid(row);
}

bool SudokuSolver::colIsValid(int col)
{
    return numberIsValid(col);
}

bool SudokuSolver::sameDigitInRow(int row, int col, int digit)
{
    for (int c = 0; c < NINE; c++)
    {
        if (c != col)
        {
            if (_sol[row][c].state() != State::empty)
            {
                if (_sol[row][c].value() == digit)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool SudokuSolver::sameDigitInCol(int row, int col, int digit)
{
    for (int r = 0; r < NINE; r++)
    {
        if (r != row)
        {
            if (_sol[r][col].state() != State::empty)
            {
                if (_sol[r][col].value() == digit)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool SudokuSolver::sameDigitInSubGrid(int row, int col, int digit)
{
    //First determine in which subgrid we are
    int vertical, horiz;

    if (row < THREE)
    {
        vertical = 0;
    }
    else if (row < SIX)
    {
        vertical = THREE;
    }
    else
    {
        vertical = SIX;
    }

    if (col < THREE)
    {
        horiz = 0;
    }
    else if (col < SIX)
    {
        horiz = THREE;
    }
    else
    {
        horiz = SIX;
    }

    //Then figure out if there is a dupe digit in the sub grid
    for (int r = 0; r < THREE; r++)
    {
        for (int c = 0; c < THREE; c++)
        {
            if ((r + vertical != row) && (c + horiz != col)) //Don't test cell against itself
            {
                if (_sol[r + vertical][c + horiz].state() != State::empty)
                {
                    if (_sol[r + vertical][c + horiz].value() == digit)
                    {
                        return true;
                    }
                }
            }
        }

    }
    return false;
}

bool SudokuSolver::sameDigitFound(int row, int col, int digit)
{
    bool test1 = sameDigitInRow(row, col, digit);
    bool test2 = sameDigitInCol(row, col, digit);
    bool test3 = sameDigitInSubGrid(row, col, digit);
    return (test1 || test2 || test3);
}
