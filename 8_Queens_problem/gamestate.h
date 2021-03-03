#ifndef GAMESTATE_H
#define GAMESTATE_H
//Provides an object consisting of a 2D array that represents the state of play of a game
//Is used as a composed member of the GameBoard class

#include <string>

//#typedef std::string * row; //do later

class GameState
{
public:
    GameState(int rows = 8, int columns = 8);
    std::string getCell(int row, int column) const;
        //returns the value for the cell specified by row and column
    void setCell(int row, int column, std::string value);
        //sets the value for the cell specified by row and column



private:
    int _rows;
    int _columns;
    //std::string * _row;
    std::string ** _rowCollection;

};

#endif // GAMESTATE_H
