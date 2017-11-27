//===========================================================================

#include <Sprites.h>
#include "GameOverScreen.h"
#include "TimePrinter.h"
#include "Score.h"
#include "Assets.h"

//===========================================================================
GameOverScreen::GameOverScreen(
    Arduboy2Base& arduboy,
    Tinyfont& tinyfont,
    Background& background
):
    WaitStage(arduboy),
    tinyfont(tinyfont),
    background(background),
    message(tinyfont, 5, HEIGHT - 7, "push any button to cont.", WHITE)
{
    setFrames(0);
    setFinishOnButtonEvent(true);
}

//===========================================================================
void GameOverScreen::process() {
    WaitStage::process();
    background.update();
    message.update();
}

//===========================================================================
void GameOverScreen::draw() const {
    getArduboy().clear();
    background.draw();
    drawText();
    message.draw();
}

//===========================================================================
void GameOverScreen::drawText() const {
    getArduboy().fillRect(27, 14, 16 * 5, 6, WHITE);
    tinyfont.setCursor(28, 15);
    tinyfont.setTextColor(BLACK);
    tinyfont.print("CONGRATULATIONS!");

    getArduboy().fillRect(WIDTH / 2 - 20 - 1, HEIGHT / 2 - 3, 50, 6, WHITE);
    tinyfont.setCursor(WIDTH / 2 - 20, HEIGHT / 2 - 2);
    tinyfont.print(
        (Score::getPreviousTime() == Score::getBestTime())?
            "BEST TIME!" : "YOUR TIME:"
    );

    getArduboy().fillRect(53, HEIGHT / 2 + 5, 26, 6, WHITE);
    TimePrinter::printTime(tinyfont, 54, HEIGHT / 2 + 6, Score::getPreviousTime());
}

//===========================================================================

