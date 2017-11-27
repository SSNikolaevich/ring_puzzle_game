#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H
//===========================================================================
#include <Tinyfont.h>
#include "WaitStage.h"
#include "Background.h"
#include "FlashingMessage.h"
//===========================================================================
class GameOverScreen: public WaitStage {
    public:
        GameOverScreen(
            Arduboy2Base& arduboy,
            Tinyfont& tinyfont,
            Background& background
        );
        void process() override;
        void draw() const override;
    private:
        Tinyfont& tinyfont;
        Background& background;
        FlashingMessage message;

        void drawText() const;
};

//===========================================================================
#endif
