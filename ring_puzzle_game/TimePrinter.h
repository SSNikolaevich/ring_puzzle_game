#ifndef TIME_PRINTER_H
#define TIME_PRINTER_H
//===========================================================================
#include <Tinyfont.h>
//===========================================================================
class TimePrinter {
    public:
        static void printTime(
            Tinyfont& tinyfont,
            uint8_t x,
            uint8_t y,
            uint32_t time
        );
};
//===========================================================================
#endif
