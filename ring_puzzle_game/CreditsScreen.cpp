//===========================================================================
#include <Sprites.h>
#include "Assets.h"
#include "CreditsScreen.h"
//===========================================================================
CreditsScreen::CreditsScreen(Arduboy2Base& arduboy, Tinyfont& tinyfont):
    WaitStage(arduboy),
    tinyfont(tinyfont)
{}

//===========================================================================
void CreditsScreen::draw() const {
    getArduboy().clear();
    Sprites::drawPlusMask(12, HEIGHT / 2 - 8, githubLogoSprite_plus_mask, 0);
    tinyfont.setTextColor(WHITE);
    tinyfont.setCursor(32, HEIGHT / 2 - 6);
    tinyfont.print("SSNikolaevich");
    tinyfont.setCursor(32, HEIGHT / 2 + 2);
    tinyfont.print("/ring_puzzle_game");
}

//===========================================================================
