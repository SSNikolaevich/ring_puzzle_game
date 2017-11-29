//===========================================================================

#include <Sprites.h>
#include "Assets.h"
#include "GameStage.h"
#include "Score.h"
#include "TimePrinter.h"

//===========================================================================
GameStage::GameStage(
    Arduboy2Base& arduboy,
    Tinyfont& tinyfont,
    Background& background
):
    StageBase(),
    arduboy(arduboy),
    tinyfont(tinyfont),
    background(background),
    nextStage(NULL),
    game(),
    mode(NORMAL),
    column(0),
    row(0),
    timer(0),
    bestTime(Score::getBestTime())
{
    reset();
}

//===========================================================================
void GameStage::setNextStage(Stage* stage) {
    nextStage = stage;
}

//===========================================================================
void GameStage::reset() {
    game.reset();
    column = 0;
    row = 0;
    timer = 0;
    mode = NORMAL;
    bestTime = Score::getBestTime();
    shuffle();
}

//===========================================================================
void GameStage::process() {
    background.update();
    handleInput();
    updateTimer();
    if (game.isOver()) {
        Score::setPreviousTime(timer);
    }
}

//===========================================================================
void GameStage::updateTimer() {
    if (timer < 0xFFFFFFFF) {
        ++timer;
    }
}

//===========================================================================
uint8_t GameStage::getTileWidth() const {
    return (HEIGHT - 16) / game.getColumns();
}

//===========================================================================
uint8_t GameStage::getTileHeight() const {
    return (HEIGHT - 16) / game.getRows();
}

//===========================================================================
void GameStage::draw() const {
    arduboy.clear();
    background.draw();

    drawBoard();
    drawControls();
    drawTiles();
    drawKeyBindings();
    drawVersionAndYear();
    drawElapsedTime();
    drawBestTime();
}

//===========================================================================
Stage* GameStage::getNextStage() const {
    return game.isOver()? nextStage : this;
}

//===========================================================================
void GameStage::drawBoard() const {
    arduboy.fillRect(32, 0, HEIGHT, HEIGHT, BLACK);
    arduboy.drawRect(36, 4, HEIGHT - 8, HEIGHT - 8, WHITE);
    arduboy.drawRect(38, 6, HEIGHT - 12, HEIGHT - 12, WHITE);
}

//===========================================================================
void GameStage::drawControls() const {
    const uint8_t tileWidth = getTileWidth();
    const uint8_t tileHeight = getTileHeight();
    const uint8_t offsetX = 40 + column * tileWidth;
    const uint8_t offsetY = 8 + row * tileHeight;
    switch (mode) {
        case MOVE:
            arduboy.drawRect(offsetX, 0, tileWidth, 3, WHITE);
            arduboy.drawRect(offsetX, HEIGHT - 3, tileWidth, 3, WHITE);
            arduboy.drawRect(32, offsetY, 3, tileHeight, WHITE);
            arduboy.drawRect(93, offsetY, 3, tileHeight, WHITE);
            break;
        case NORMAL:
            arduboy.fillRect(offsetX, 0, tileWidth, 3, WHITE);
            arduboy.fillRect(offsetX, HEIGHT - 3, tileWidth, 3, WHITE);
            arduboy.fillRect(32, offsetY, 3, tileHeight, WHITE);
            arduboy.fillRect(93, offsetY, 3, tileHeight, WHITE);
            break;
    }
}

//===========================================================================
void GameStage::drawKeyBindings() const {
    tinyfont.setTextColor(WHITE);
    tinyfont.setCursor(WIDTH - 30, HEIGHT - 20);
    tinyfont.print("A");
    tinyfont.setCursor(WIDTH - 26, HEIGHT - 20);
    tinyfont.print(":");
    tinyfont.setCursor(WIDTH - 23, HEIGHT - 20);
    tinyfont.print("MOVE");
    tinyfont.setCursor(WIDTH - 30, HEIGHT - 12);
    tinyfont.print("B");
    tinyfont.setCursor(WIDTH - 26, HEIGHT - 12);
    tinyfont.print(":");
    tinyfont.setCursor(WIDTH - 23, HEIGHT - 12);
    tinyfont.print("SHOW");
}

//===========================================================================
void GameStage::drawVersionAndYear() const {
    tinyfont.setTextColor(WHITE);
    tinyfont.setCursor(8, HEIGHT - 20);
    tinyfont.print("v1.1");
    tinyfont.setCursor(8, HEIGHT - 12);
    tinyfont.print("2017");
}

//===========================================================================
void GameStage::drawElapsedTime() const {
    tinyfont.setTextColor(WHITE);
    tinyfont.setCursor(WIDTH - 27, 8);
    tinyfont.print("TIME");
    TimePrinter::printTime(tinyfont, WIDTH - 29, 16, timer);
}

//===========================================================================
void GameStage::drawBestTime() const {
    tinyfont.setTextColor(WHITE);
    tinyfont.setCursor(8, 8);
    tinyfont.print("BEST");
    TimePrinter::printTime(tinyfont, 6, 16, bestTime);
}

//===========================================================================
void GameStage::drawTiles() const {
    for (uint8_t c = 0; c < game.getColumns(); ++c) {
        for (uint8_t r = 0; r < game.getRows(); ++r) {
            uint8_t tile = game.getTile(c, r);
            uint8_t x = 40 + c * getTileWidth();
            uint8_t y = 8 + r * getTileHeight();
            if (mode == SHOW) {
                x = 40 + game.getTargetColumn(tile) * getTileWidth();
                y = 8 + game.getTargetRow(tile) * getTileWidth();
            }
            drawTile(x, y, tile);
        }
    }
}

//===========================================================================
void GameStage::drawTile(uint8_t x, uint8_t y, uint8_t tile) {
    Sprites::drawPlusMask(x, y, tilesSprite_plus_mask, tile);
}

//===========================================================================
void GameStage::handleInput() {
    switch (mode) {
        case NORMAL  : handleNormalModeInput(); break;
        case MOVE    : handleMoveModeInput();   break;
        case SHOW    : handleShowModeInput();   break;
    }
}

//===========================================================================
void GameStage::handleNormalModeInput() {
    if (arduboy.justPressed(A_BUTTON)) {
        mode = MOVE;
    } else if (arduboy.justPressed(B_BUTTON)) {
        mode = SHOW;
    } else {
        if (arduboy.justPressed(LEFT_BUTTON)) {
            column = (column + COLUMNS - 1) % COLUMNS;
        } else if (arduboy.justPressed(RIGHT_BUTTON)) {
            column = (column + 1) % COLUMNS;
        }
        if (arduboy.justPressed(UP_BUTTON)) {
            row = (row + ROWS - 1) % ROWS;
        } else if (arduboy.justPressed(DOWN_BUTTON)) {
            row = (row + 1) % ROWS;
        }
    }
}

//===========================================================================
void GameStage::handleMoveModeInput() {
    if (arduboy.justReleased(A_BUTTON)) {
        mode = NORMAL;
    } else {
        if (arduboy.justPressed(LEFT_BUTTON)) {
            game.makeMove(column, row, LEFT);
        } else if (arduboy.justPressed(RIGHT_BUTTON)) {
            game.makeMove(column, row, RIGHT);
        } else if (arduboy.justPressed(UP_BUTTON)) {
            game.makeMove(column, row, UP);
        } else if (arduboy.justPressed(DOWN_BUTTON)) {
            game.makeMove(column, row, DOWN);
        }
    }
}

//===========================================================================
void GameStage::handleShowModeInput() {
    if (arduboy.justReleased(B_BUTTON)) {
        mode = NORMAL;
    }
}

//===========================================================================
void GameStage::shuffle() {
    uint8_t counter = game.getColumns() * game.getRows();
    while (counter-- || game.isOver()) {
        const uint8_t c = random(1, game.getColumns());
        const uint8_t r = random(1, game.getRows());
        Direction direction = random(2)? RIGHT : DOWN;
        game.makeMove(c, r, direction);
    }
}

//===========================================================================
