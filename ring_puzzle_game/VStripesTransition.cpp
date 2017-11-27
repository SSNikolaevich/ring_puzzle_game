//===========================================================================

#include "VStripesTransition.h"

//===========================================================================
VStripesTransition::VStripesTransition(const Arduboy2Base& arduboy):
    TransitionStage(),
    arduboy(arduboy),
    direction(RIGHT),
    color(WHITE),
    stripeWidth(16)
{}

//===========================================================================
void VStripesTransition::setDirection(Direction Direction) {
    this->direction = direction;
}

//===========================================================================
void VStripesTransition::setColor(uint8_t color) {
    this->color = color;
}

//===========================================================================
void VStripesTransition::setStripeWidth(uint8_t width) {
    stripeWidth = width;
}

//===========================================================================
boolean VStripesTransition::isDone() const {
    return getProgress() >= (stripeWidth + 1) * 2;
}

//===========================================================================
void VStripesTransition::drawTransitionEffect() const {
    const uint8_t stripesCount = WIDTH / stripeWidth;
    const uint8_t delta = getProgress() % (stripeWidth + 1);
    const uint8_t w = isFirstStage()? delta : stripeWidth - delta;
    for (uint8_t i = 0; i < stripesCount; ++i) {
        const uint8_t offset = stripeWidth * i;
        const uint8_t x = (direction == RIGHT)?
            (isFirstStage()? offset : (offset + delta))
              : (isFirstStage()? offset + stripeWidth - delta: offset);
        arduboy.fillRect(x, 0, w, HEIGHT, color);
    }
}

//===========================================================================
boolean VStripesTransition::isFirstStage() const {
    return getProgress() < (stripeWidth + 1);
}

//===========================================================================
