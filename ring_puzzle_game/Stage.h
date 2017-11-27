#ifndef STAGE_H
#define STAGE_H
//===========================================================================
#include <Arduino.h>
//===========================================================================
class Stage {
    public:
        virtual void reset() = 0;
        virtual void process() = 0;
        virtual void draw() const = 0;
        virtual Stage* getNextStage() const = 0;
        virtual boolean resetOnEnter() const = 0;
        virtual ~Stage();
};

//===========================================================================
#endif

