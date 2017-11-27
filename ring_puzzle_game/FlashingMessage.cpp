//===========================================================================

#include "FlashingMessage.h"

//===========================================================================
FlashingMessage::FlashingMessage(
    Tinyfont& tinyfont,
    uint8_t x,
    uint8_t y,
    const char* message,
    uint8_t color
):
    tinyfont(tinyfont),
    x(x),
    y(y),
    message(message),
    color(color),
    counter(0)
{}

//===========================================================================
void FlashingMessage::update() {
    ++counter;
}

//===========================================================================
void FlashingMessage::draw() const {
    if ((counter % 64) < 48) {
        tinyfont.setTextColor(color);
        tinyfont.setCursor(x, y);
        tinyfont.print(message);
    }
}

//===========================================================================

