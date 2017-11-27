//===========================================================================

#include <Sprites.h>
#include "MainScreen.h"
#include "Assets.h"

//===========================================================================
MainScreen::MainScreen(
    Arduboy2Base& arduboy,
    Tinyfont& tinyfont,
    Background& background
):
    WaitStage(arduboy),
    tinyfont(tinyfont),
    background(background),
    message(tinyfont, 5, HEIGHT - 7, "push any button to start", WHITE)
{
    setFrames(0);
    setFinishOnButtonEvent(true);
}

//===========================================================================
void MainScreen::process() {
    WaitStage::process();
    background.update();
    message.update();
}

//===========================================================================
void MainScreen::draw() const {
    getArduboy().clear();
    background.draw();
    Sprites::drawPlusMask(20, 4, titleSprite_plus_mask, 0);
    message.draw();
}

//===========================================================================

