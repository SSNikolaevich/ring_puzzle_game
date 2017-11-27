#ifndef COMPLETE_PUZZLE_SCEEN_H
#define COMPLETE_PUZZLE_SCEEN_H
//===========================================================================
#include <Arduboy2.h>
#include <Tinyfont.h>
#include "WaitStage.h"
#include "Background.h"
#include "FlashingMessage.h"
//===========================================================================
class CompletePuzzleScreen: public WaitStage {
    public:
        CompletePuzzleScreen(
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

