#ifndef BACKGROUND_H
#define BACKGROUND_H
//===========================================================================
#include <Arduboy2.h>
//===========================================================================
#define BACKGROUND_PARTICLE_COUNT 32
#define BACKGROUND_PARTICLE_MAX_SPEED 4
//===========================================================================
class Background {
    public:
        Background(const Arduboy2Base& arduboy);
        void update();
        void draw() const;
    private:
        struct Particle {
            int8_t x;
            int8_t y;
            int8_t speed;
        };
    private:
        const Arduboy2Base& arduboy;
        Particle particles[BACKGROUND_PARTICLE_COUNT];

        void initParticle(Particle& p) const;
        void updateParticle(Particle& p) const;
        void drawParticle(const Particle& p) const;
};

//===========================================================================
#endif
