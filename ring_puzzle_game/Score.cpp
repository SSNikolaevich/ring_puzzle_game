//===========================================================================

#include "Score.h"
#include <Arduboy2.h>

//===========================================================================
#define EEPROM_BEST_TIME (EEPROM_STORAGE_SPACE_START + 42)
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
    EEPROM.put(EEPROM_BEST_TIME, time);
}

//===========================================================================
uint32_t Score::readTimeFromEEPROM() {
    uint32_t value(0);
    EEPROM.get(EEPROM_BEST_TIME, value);
    return value;
}

//===========================================================================

