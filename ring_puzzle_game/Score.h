#ifndef SCORE_H
#define SCORE_H
//===========================================================================
#include <Arduino.h>
//===========================================================================
class Score {
    public:
        static void init();
        static uint32_t getPreviousTime();
        static uint32_t getBestTime();

        static void setPreviousTime(uint32_t time);
    private:
        static uint32_t bestTime;
        static uint32_t previousTime;

        static void writeTimeToEEPROM(uint32_t time);
        static uint32_t readTimeFromEEPROM();
};

//===========================================================================
#endif

