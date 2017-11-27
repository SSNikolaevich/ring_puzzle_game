#ifndef V_STRIPES_TRANSITION_H
#define V_STRIPES_TRANSITION_H
//===========================================================================
#include <Arduboy2.h>
#include "TransitionStage.h"
#include "Direction.h"
//===========================================================================
class VStripesTransition: public TransitionStage {
    public:
        VStripesTransition(const Arduboy2Base& arduboy);
        void setColor(uint8_t color);
        void setDirection(Direction direction);
        void setStripeWidth(uint8_t width);
    protected:
        boolean isDone() const override;
        void drawTransitionEffect() const override;
        boolean isFirstStage() const override;
    private:
        const Arduboy2Base& arduboy;
        Direction direction;
        uint8_t color;
        uint8_t stripeWidth;
};

//===========================================================================
#endif

