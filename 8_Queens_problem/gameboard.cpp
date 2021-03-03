#include "gameboard.h"
#include <cassert>
#include <iostream>
#include <string>

const std::string CELL_WALL_HORIZ = "---+";



GameBoard::GameBoard(int rows, int columns) : _rows(rows), _columns(columns)
{
    assert(_rows > 0);
    assert(_columns > 0);
}

void GameBoard::draw(const GameState *state)
{
    drawColumnNumbers();
    drawHorizEdge();
    for (int i = 0; i < _rows; i++)
    {
        drawRow(state, i);
    }

}

void GameBoard::drawColumnNumbers()
{
    std::cout << "   |";
    for (int i = 0; i < _columns; i++)
    {
        std::cout << " " << i << " |";
    }
    std::cout << '\n';
}

void GameBoard::drawHorizEdge()
{
    std::cout << CELL_WALL_HORIZ;
    for (int i = 0; i < _columns; i++)
    {
        std::cout << CELL_WALL_HORIZ;
    }
    std::cout << '\n';
}

void GameBoard::drawRow(const GameState *state, int row)
{
    if (state != nullptr)
    {
        //Draw the row containing values
        std::cout << " " << row << " |";
        for (int j = 0; j < _columns; j++)
        {
            std::cout << " " << state->getCell(row, j) << " |";
        }
        std::cout << '\n';

        //Draw the bottom border
        drawHorizEdge();
        std::cout << '\n';
    }
    else
    {
        //Draw an empty board
        std::cout << " " << row << " |";
        for (int j = 0; j < _columns; j++)
        {
            std::cout << "   |";
        }
        std::cout << '\n';

        //Draw the bottom border
        drawHorizEdge();
        std::cout << '\n';
    }
}
