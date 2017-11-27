//===========================================================================

#include "TransitionStage.h"

//===========================================================================
TransitionStage::TransitionStage():
    StageBase(),
    skippedFramesCount(0),
    fromStage(NULL),
    toStage(NULL),
    resetToStage(false),
    progress(0),
    frames(0)
{}

//===========================================================================
void TransitionStage::setSkippedFramesCount(uint8_t count) {
    skippedFramesCount = count;
}

//===========================================================================
void TransitionStage::setFromStage(Stage* stage) {
    fromStage = stage;
}

//===========================================================================
void TransitionStage::setToStage(Stage* stage) {
    toStage = stage;
}

//===========================================================================
void TransitionStage::setResetToStage(boolean state) {
    resetToStage = state;
}

//===========================================================================
void TransitionStage::reset() {
    progress = 0;
    frames = 0;
    if (resetToStage || toStage) {
        toStage->reset();
    }
}

//===========================================================================
void TransitionStage::process() {
    processStage();
    update();
}

//===========================================================================
void TransitionStage::draw() const {
    drawStage();
    drawTransitionEffect();
}

//===========================================================================
Stage* TransitionStage::getNextStage() const {
    return isDone()? toStage : this;
}

//===========================================================================
uint8_t TransitionStage::getProgress() const {
    return progress;
}

//===========================================================================
boolean TransitionStage::skipFrame() const {
return skippedFramesCount && (frames % (skippedFramesCount + 1) != 0);
}

//===========================================================================
void TransitionStage::update() {
    if (!skipFrame()) {
        ++progress;
    }
    ++frames;
}

//===========================================================================
void TransitionStage::processStage() const {
    Stage* stage = isFirstStage()? fromStage : toStage;
    if (stage) {
        stage->process();
    }
}

//===========================================================================
void TransitionStage::drawStage() const {
    Stage* stage = isFirstStage()? fromStage : toStage;
    if (stage) {
        stage->draw();
    }
}

//===========================================================================

