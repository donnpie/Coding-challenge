#include "gamestate.h"
#include <cassert>

GameState::GameState(int rows, int columns) : _rows(rows), _columns(columns)
{
    assert(_rows > 0);
    assert(_columns > 0);

    //_row = new std::string[_columns];
    _rowCollection = new std::string*[_rows];
    for (int i = 0; i < _rows; i++)
    {
        _rowCollection[i] = new std::string[_columns];
        for (int j = 0; j < _columns; ++j)
        {
            _rowCollection[i][j] = " ";
        }
    }


}

std::string GameState::getCell(int row, int column) const
{
    return _rowCollection[row][column];
}

void GameState::setCell(int row, int column, std::string value)
{
    _rowCollection[row][column] = value;
}
