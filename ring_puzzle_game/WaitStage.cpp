//===========================================================================
#include "WaitStage.h"
//===========================================================================
WaitStage::WaitStage(Arduboy2Base& arduboy):
    StageBase(),
    arduboy(arduboy),
    frames(0),
    finishOnButtonEvent(true),
    nextStage(NULL),
    progress(0),
    isButtonPressed(false)
{}

//===========================================================================
void WaitStage::setFrames(int8_t frames) {
    this->frames = frames;
}

//===========================================================================
void WaitStage::setFinishOnButtonEvent(boolean state) {
    finishOnButtonEvent = state;
}

//===========================================================================
void WaitStage::setNextStage(Stage* stage) {
    this->nextStage = stage;
}

//===========================================================================
void WaitStage::reset() {
    progress = 0;
    isButtonPressed = false;
}

//===========================================================================
void WaitStage::process() {
    isButtonPressed = isButtonPressed
        || arduboy.justPressed(A_BUTTON)
        || arduboy.justPressed(B_BUTTON);
    ++progress;
}

//===========================================================================
void WaitStage::draw() const {
}

//===========================================================================
Stage* WaitStage::getNextStage() const {
    return isDone()? nextStage : this;
}

//===========================================================================
boolean WaitStage::isDone() const {
    return ((frames > 0) && (progress >= frames))
        || (isButtonPressed && finishOnButtonEvent);
}

//===========================================================================
Arduboy2Base& WaitStage::getArduboy() const {
    return arduboy;
}

//===========================================================================
