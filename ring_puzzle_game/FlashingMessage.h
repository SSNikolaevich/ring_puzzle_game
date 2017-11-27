#ifndef FLASHING_MESSAGE_H
#define FLASHING_MESSAGE_H
//===========================================================================
#include <Tinyfont.h>
//===========================================================================
class FlashingMessage {
    public:
        FlashingMessage(
            Tinyfont& tinyfont,
            uint8_t x,
            uint8_t y,
            const char* message,
            uint8_t color
        );
        void update();
        void draw() const;
    private:
        Tinyfont& tinyfont;
        uint8_t x;
        uint8_t y;
        const char* message;
        uint8_t color;
        uint8_t counter;
};

//===========================================================================
#endif

