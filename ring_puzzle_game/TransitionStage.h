#ifndef TRANSITION_STAGE_H
#define TRANSITION_STAGE_H
//============================================================================
#include <Arduino.h>
#include "StageBase.h"
//============================================================================
class TransitionStage: public StageBase {
    public:
        TransitionStage();

        void setSkippedFramesCount(uint8_t count);
        void setFromStage(Stage* stage);
        void setToStage(Stage* stage);
        void setResetToStage(boolean state);

        void reset() override;
        void process() override;
        void draw() const override;
        Stage* getNextStage() const override;
    protected:
        virtual boolean isDone() const = 0;
        virtual boolean isFirstStage() const = 0;
        virtual void drawTransitionEffect() const = 0;
        uint8_t getProgress() const;
    private:
        uint8_t skippedFramesCount;
        Stage* fromStage;
        Stage* toStage;
        boolean resetToStage;
        uint8_t progress;
        uint8_t frames;

        boolean skipFrame() const;
        void update();
        void processStage() const;
        void drawStage() const;
};

//===========================================================================
#endif

