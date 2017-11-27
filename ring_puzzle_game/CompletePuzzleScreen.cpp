//===========================================================================
#include <Sprites.h>
#include "Assets.h"
#include "CompletePuzzleScreen.h"
//===========================================================================
CompletePuzzleScreen::CompletePuzzleScreen(
    Arduboy2Base& arduboy,
    Tinyfont& tinyfont,
    Background& background
):
    WaitStage(arduboy),
    tinyfont(tinyfont),
    background(background),
    message(tinyfont, 5, HEIGHT - 7, "push any button to cont.", WHITE)
{}

//===========================================================================
void CompletePuzzleScreen::process() {
    WaitStage::process();
    message.update();
    background.update();
}

//===========================================================================
void CompletePuzzleScreen::draw() const {
    getArduboy().clear();
    background.draw();

    for (uint8_t c = 0; c < 4; ++c) {
        for (uint8_t r = 0; r < 4; ++r) {
            const uint8_t x = 40 + c * 12;
            const uint8_t y = 8 + r * 12;
            const uint8_t tile = c * 4 + r;
            Sprites::drawPlusMask(x, y, tilesSprite_plus_mask, tile);
        }
    }

    message.draw();
}

//===========================================================================

