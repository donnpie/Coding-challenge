#ifndef NQUEENSSOLUTION_H
#define NQUEENSSOLUTION_H
#include <cassert>

//Provides a data structure that holds the solution to the n queens problem
//


class nQueensSolution
{
public:
    nQueensSolution(int columns = 8);
    void setValue(int row, int col);
        //Sets the value in column col to row
    int getValue(int col);
        //Returns the row value in column col
    int getColumnCount();
        //Returns the number of columns on the board
    void printSolution();
        //Prints the solution to console

private:
    int * _sol;
    int _columnCount;
};

#endif // NQUEENSSOLUTION_H
