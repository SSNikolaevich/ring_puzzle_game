#ifndef GAME_STAGE_H
#define GAME_STAGE_H
//===========================================================================
#include <Tinyfont.h>
#include "StageBase.h"
#include "Background.h"
#include "Game.h"
//===========================================================================
class GameStage: public StageBase {
    public:
        GameStage(
            Arduboy2Base& arduboy,
            Tinyfont& tinyfont,
            Background& background
        );

        void setNextStage(Stage* stage);

        void reset() override;
        void process() override;
        void draw() const override;
        Stage* getNextStage() const override;

    private:
        enum Mode {
            NORMAL,
            MOVE,
            SHOW
        };

    private:
        Arduboy2Base& arduboy;
        Tinyfont& tinyfont;
        Background& background;
        Stage* nextStage;

        Game game;
        Mode mode;
        uint8_t column;
        uint8_t row;

        uint32_t timer;
        uint32_t bestTime;

        void shuffle();

        uint8_t getTileWidth() const;
        uint8_t getTileHeight() const;

        void handleInput();
        void handleNormalModeInput();
        void handleMoveModeInput();
        void handleShowModeInput();

        void updateTimer();

        void drawBoard() const;
        void drawControls() const;
        void drawTiles() const;
        void drawTile(uint8_t x, uint8_t y, uint8_t tile);
        void drawKeyBindings() const;
        void drawVersionAndYear() const;
        void drawElapsedTime() const;
        void drawBestTime() const;
};
//===========================================================================
#endif
