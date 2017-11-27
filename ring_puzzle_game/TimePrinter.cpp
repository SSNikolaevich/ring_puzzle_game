//===========================================================================

#include "TimePrinter.h"

//===========================================================================
void TimePrinter::printTime(
    Tinyfont& tinyfont,
    uint8_t x,
    uint8_t y,
    uint32_t time
) {
    int seconds = (time / 60) % 60 ;
    int minutes = time / 3600;
    if ((!time) || (minutes > 99)) {
        tinyfont.setCursor(x, y);
        tinyfont.print("--:--");
    } else {
        tinyfont.printChar('0' + ((minutes % 100) / 10), x, y);
        tinyfont.printChar('0' + ((minutes % 100) % 10), x + 5, y);
        tinyfont.printChar(':', x + 10, y);
        tinyfont.printChar('0' + seconds / 10, x + 15, y);
        tinyfont.printChar('0' + seconds % 10, x + 20, y);
    }
}

//===========================================================================
