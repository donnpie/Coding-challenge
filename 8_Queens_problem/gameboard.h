#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//Provides a class that draws a generic game board on the screen
//A board consists of a number of rows and columns, specified at instantiation
//Cells on the board can be accessed in a variety of ways
//Takes a game state as input. A game state is a 2D array containing the state data of the board
//The state must have the same number of rows and columns as the board

#include "gamestate.h"



class GameBoard
{
public:
    GameBoard(int rows = 8, int columns = 8);
    void draw(const GameState *state = nullptr);
        //Draws or redraws the board



private:
    //helper methods for drawing the board
    void drawColumnNumbers();
        //Draw column numbers accross the top of the board
    void drawHorizEdge();
        //Draws the top edge of the board
    void drawRow(const GameState *state = nullptr, int row = 0);
        //Draws a single row, including ides and bottom
        //Row to be drawn is specified by row


private:
    int _rows;
    int _columns;

};

#endif // GAMEBOARD_H
