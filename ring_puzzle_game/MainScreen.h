#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H
//===========================================================================
#include <Tinyfont.h>
#include "WaitStage.h"
#include "Background.h"
#include "FlashingMessage.h"
//===========================================================================
class MainScreen: public WaitStage {
    public:
        MainScreen(
            Arduboy2Base& arduboy,
            Tinyfont& tinyfont,
            Background& background
        );
        void process() override;
        void draw() const override;
    private:
        Tinyfont& tinyfont;
        Background& background;
        FlashingMessage message;
};

//===========================================================================
#endif
