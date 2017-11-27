#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H
//===========================================================================
#include <Arduboy2.h>
#include <Tinyfont.h>
#include "WaitStage.h"
//===========================================================================
class CreditsScreen: public WaitStage {
    public:
        CreditsScreen(Arduboy2Base& arduboy, Tinyfont& tinyfont);
        void draw() const override;
    private:
        Tinyfont& tinyfont;
};

//===========================================================================
#endif
