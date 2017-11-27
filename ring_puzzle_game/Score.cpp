//===========================================================================

#include "Score.h"

//===========================================================================

uint32_t Score::bestTime = 0;
uint32_t Score::previousTime = 0;

//===========================================================================
void Score::init() {
    bestTime = readTimeFromEEPROM();
}

//===========================================================================
uint32_t Score::getPreviousTime() {
    return previousTime;
}

//===========================================================================
uint32_t Score::getBestTime() {
    return bestTime;
}

//===========================================================================
void Score::setPreviousTime(uint32_t time) {
    if (!bestTime || (bestTime > time)) {
        bestTime = time;
        writeTimeToEEPROM(bestTime);
    }
    previousTime = time;
}

//===========================================================================
void Score::writeTimeToEEPROM(uint32_t time) {
    // TODO
}

//===========================================================================
uint32_t Score::readTimeFromEEPROM() {
    // TODO
    return 0;
}

//===========================================================================

