#include <iostream>
#include "nqueensproblem.h"
#include "nqueenssolution.h"
#include "gameboard.h"
#include "gamestate.h"

//Demonstrates a recursive, backtracking solution to the 8 queens problem


int main()
{
    {
        const int SIZE = 8;
        nQueensSolution sol(SIZE); //Default is 8r by 8c
        nQueensProblem prob(SIZE, &sol);

        sol.printSolution();
        prob.placeQueen(0);
        //sol.printSolution();

        //Transfer the result to game board
        GameState state(SIZE, SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            state.setCell(sol.getValue(i), i, "Q");
        }
        GameBoard board(SIZE, SIZE);
        board.draw(&state);
    }



    return 0;
}
