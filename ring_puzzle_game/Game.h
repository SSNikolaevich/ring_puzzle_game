#ifndef GAME_H
#define GAME_H
//===========================================================================
#include <Arduino.h>
#include "Direction.h"
//===========================================================================
#define COLUMNS 4
#define ROWS 4
//===========================================================================
class Game {
    public:
        Game();
        uint8_t getRows() const;
        uint8_t getColumns() const;
        uint8_t getTile(uint8_t column, uint8_t row) const;

        boolean isOver() const;
        uint8_t getTargetColumn(uint8_t tile) const;
        uint8_t getTargetRow(uint8_t tile) const;

        void reset();
        void makeMove(uint8_t column, uint8_t row, Direction direction);
    private:
        uint8_t tiles[COLUMNS * ROWS];

        uint8_t getIndex(uint8_t column, uint8_t row) const;
        void setTile(uint8_t column, uint8_t row, uint8_t tile);
};
//===========================================================================
#endif
