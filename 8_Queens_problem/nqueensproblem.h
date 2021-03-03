#ifndef NQUEENSPROBLEM_H
#define NQUEENSPROBLEM_H

//Calculates the soloution to the n queens problem
//The solution is stored in an external object of type nQueensSolution
#include "nqueenssolution.h"


class nQueensProblem
{
public:
    nQueensProblem(int columns = 8, nQueensSolution *sol = nullptr);

    //void placeQueen(int column);
        //Stating at column 0, recursively place queens in the solution object sol until all columns are filled
    bool placeQueen(int column);

private:
    //Helper functions
    bool inSameDiagonal(int r, int c);
        //Returns true if there are any other queens on the same diagonal as the cell specified by (r, c)
    bool inSameRow(int r, int c);
        //Returns true if there are any other queens on the same row as the cell specified by (r, c)
    bool inSameColumn(int c);
        //Returns true if there are any other queens on the same colum as the column specified by c
    bool isSafe(int r, int c);
        //Returns true if it is safe to place a queen on cell (r, c)



    int _columnCount;
    int _rowCount;
    nQueensSolution *_sol;
    int _watchDog;
};


#endif // NQUEENSPROBLEM_H
