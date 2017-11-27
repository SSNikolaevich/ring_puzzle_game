//===========================================================================

#include "Game.h"

//===========================================================================
Game::Game():
    tiles()
{
    reset();
}

//===========================================================================
uint8_t Game::getRows() const {
    return ROWS;
}

//===========================================================================
uint8_t Game::getColumns() const {
    return COLUMNS;
}

//===========================================================================
uint8_t Game::getTile(uint8_t column, uint8_t row) const {
    return tiles[getIndex(column, row)];
}

//===========================================================================
boolean Game::isOver() const {
    for (uint8_t i = 0; i < COLUMNS * ROWS; ++i) {
        if (tiles[i] != i) {
            return false;
        }
    }
    return true;
}

//===========================================================================
uint8_t Game::getTargetColumn(uint8_t tile) const {
    return tile / ROWS;
}

//===========================================================================
uint8_t Game::getTargetRow(uint8_t tile) const {
    return tile % ROWS;
}

//===========================================================================
void Game::reset() {
    for (uint8_t i = 0; i < COLUMNS * ROWS; ++i) {
        tiles[i] = i;
    }
}

//===========================================================================
uint8_t Game::getIndex(uint8_t column, uint8_t row) const {
    return (column % COLUMNS) * ROWS + (row % ROWS);
}

//===========================================================================
void Game::setTile(uint8_t column, uint8_t row, uint8_t tile) {
    tiles[getIndex(column, row)] = tile;
}

//===========================================================================
void Game::makeMove(uint8_t column, uint8_t row, Direction direction) {
    uint8_t dc = 0;
    uint8_t dr = 0;
    uint8_t counter = 0;
    switch (direction) {
        case RIGHT : dc = 1;           dr = 0;        counter = getColumns(); break;
        case LEFT  : dc = COLUMNS - 1; dr = 0;        counter = getColumns(); break;
        case DOWN  : dc = 0;           dr = 1;        counter = getRows();    break;
        case UP    : dc = 0;           dr = ROWS - 1; counter = getRows();    break;
    }
    uint8_t c = column;
    uint8_t r = row;
    uint8_t tile = getTile(c, r);
    while (counter--) {
        c += dc;
        r += dr;
        uint8_t t = getTile(c, r);
        setTile(c, r, tile);
        tile = t;
    }
}

//===========================================================================
