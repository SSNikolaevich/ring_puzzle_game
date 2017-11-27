#ifndef STAGE_BASE_H
#define STAGE_BASE_H
//===========================================================================
#include "Stage.h"
//===========================================================================
class StageBase: public Stage {
    public:
        StageBase();
        void setResetOnEnter(boolean state);
        boolean resetOnEnter() const override;
    private:
        boolean _resetOnEnter;
};

//===========================================================================
#endif
