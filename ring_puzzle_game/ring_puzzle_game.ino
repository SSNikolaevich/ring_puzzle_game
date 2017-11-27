//============================================================================

#include <Arduboy2.h>
#include <Tinyfont.h>
#include "Score.h"
#include "Stage.h"
#include "WaitStage.h"
#include "TransitionStage.h"
#include "VStripesTransition.h"
#include "Background.h"
#include "MainScreen.h"
#include "GameStage.h"
#include "CompletePuzzleScreen.h"
#include "GameOverScreen.h"
#include "CreditsScreen.h"

//============================================================================

Arduboy2Base arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

Background background(arduboy);
VStripesTransition bootLogoToMainScreenTransition(arduboy);
VStripesTransition mainScreenToGameTransition(arduboy);
MainScreen mainScreen(arduboy, tinyfont, background);
WaitStage bootLogoWaitStage(arduboy);
GameStage gameStage(arduboy, tinyfont, background);
CompletePuzzleScreen completePuzzleScreen(arduboy, tinyfont, background);
GameOverScreen gameOverScreen(arduboy, tinyfont, background);
VStripesTransition gameOverScreenToCreditsScreenTransition(arduboy);
CreditsScreen creditsScreen(arduboy, tinyfont);
VStripesTransition creditsScreenToMainScreenTransition(arduboy);

Stage* stage = &bootLogoWaitStage;

//============================================================================
void setup() {
    // put your setup code here, to run once:

    arduboy.boot(); // raw hardware
    arduboy.blank(); // blank the display
    arduboy.flashlight(); // light the RGB LED and screen if UP button is being held.  
    arduboy.systemButtons();// check for and handle buttons held during start up for system control
    arduboy.audio.begin();
    arduboy.bootLogoSpritesSelfMasked();

    do {// wait for all buttons to be released
        arduboy.delayShort(50);
    } while (arduboy.buttonsState());

    // init random number generator
    arduboy.initRandomSeed();

    // setting frame rate
    arduboy.setFrameRate(60);

    // init game
    init_game();
}

//============================================================================
void loop() {
    // put your main code here, to run repeatedly:
    if (!arduboy.nextFrame()) {
        return; // go back to the start of the loop
    }
    arduboy.pollButtons();

    if (stage) {
        stage->draw();
        stage->process();
        Stage* nextStage = stage->getNextStage();
        if (nextStage && (nextStage != stage) && nextStage->resetOnEnter()) {
            nextStage->reset();
        }
        stage = nextStage;
    }

    arduboy.display();
}

//============================================================================
void init_game() {
    Score::init();

    bootLogoWaitStage.setFrames(60);
    bootLogoWaitStage.setFinishOnButtonEvent(false);
    bootLogoWaitStage.setNextStage(&bootLogoToMainScreenTransition);

    bootLogoToMainScreenTransition.setDirection(RIGHT);
    bootLogoToMainScreenTransition.setColor(WHITE);
    bootLogoToMainScreenTransition.setStripeWidth(16);
    bootLogoToMainScreenTransition.setSkippedFramesCount(2);
    bootLogoToMainScreenTransition.setFromStage(NULL);
    bootLogoToMainScreenTransition.setToStage(&mainScreen);

    mainScreen.setNextStage(&mainScreenToGameTransition);

    mainScreenToGameTransition.setDirection(RIGHT);
    mainScreenToGameTransition.setColor(BLACK);
    mainScreenToGameTransition.setStripeWidth(16);
    mainScreenToGameTransition.setSkippedFramesCount(2);
    mainScreenToGameTransition.setFromStage(&mainScreen);
    mainScreenToGameTransition.setResetToStage(true);
    mainScreenToGameTransition.setToStage(&gameStage);
    mainScreenToGameTransition.setResetToStage(true);
    mainScreenToGameTransition.setResetOnEnter(true);

    gameStage.setNextStage(&completePuzzleScreen);
    gameStage.reset();

    completePuzzleScreen.setNextStage(&gameOverScreen);
    completePuzzleScreen.setResetOnEnter(true);

    gameOverScreen.setNextStage(&gameOverScreenToCreditsScreenTransition);
    gameOverScreen.setResetOnEnter(true);

    gameOverScreenToCreditsScreenTransition.setDirection(RIGHT);
    gameOverScreenToCreditsScreenTransition.setColor(BLACK);
    gameOverScreenToCreditsScreenTransition.setStripeWidth(16);
    gameOverScreenToCreditsScreenTransition.setSkippedFramesCount(2);
    gameOverScreenToCreditsScreenTransition.setFromStage(&gameOverScreen);
    gameOverScreenToCreditsScreenTransition.setResetToStage(true);
    gameOverScreenToCreditsScreenTransition.setToStage(&creditsScreen);
    gameOverScreenToCreditsScreenTransition.setResetToStage(true);
    gameOverScreenToCreditsScreenTransition.setResetOnEnter(true);

    creditsScreen.setNextStage(&creditsScreenToMainScreenTransition);
    creditsScreen.setResetOnEnter(true);
    creditsScreen.setFrames(120);

    creditsScreenToMainScreenTransition.setDirection(RIGHT);
    creditsScreenToMainScreenTransition.setColor(WHITE);
    creditsScreenToMainScreenTransition.setStripeWidth(16);
    creditsScreenToMainScreenTransition.setSkippedFramesCount(2);
    creditsScreenToMainScreenTransition.setFromStage(&creditsScreen);
    creditsScreenToMainScreenTransition.setToStage(&mainScreen);
    creditsScreenToMainScreenTransition.setResetOnEnter(true);
}

//============================================================================
