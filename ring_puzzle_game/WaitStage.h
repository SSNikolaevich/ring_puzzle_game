#ifndef WAIT_STAGE_H
#define WAIT_STAGE_H
//===========================================================================
#include <Arduboy2.h>
#include "StageBase.h"
//===========================================================================
class WaitStage: public StageBase {
    public:
        WaitStage(Arduboy2Base& arduboy);

        void setFrames(int8_t frames);
        void setFinishOnButtonEvent(boolean state);
        void setNextStage(Stage* stage);

        void reset() override;
        void process() override;
        void draw() const override;
        Stage* getNextStage() const override;
    protected:
        Arduboy2Base& getArduboy() const;
    private:
        Arduboy2Base& arduboy;
        int8_t frames;
        boolean finishOnButtonEvent;
        Stage* nextStage;
        int8_t progress;
        boolean isButtonPressed;

        boolean isDone() const;
};

//===========================================================================
#endif

