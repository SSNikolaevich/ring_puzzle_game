//===========================================================================

#include "Background.h"

//===========================================================================
Background::Background(const Arduboy2Base& arduboy):
    arduboy(arduboy),
    particles()
{
    for (uint8_t i = 0; i < BACKGROUND_PARTICLE_COUNT; ++i) {
        initParticle(particles[i]);
    }
}

//===========================================================================
void Background::initParticle(Particle& p) const {
    p.x = random(WIDTH);
    p.y = random(HEIGHT);
    p.speed = random(1, BACKGROUND_PARTICLE_MAX_SPEED + 1);
    if (random(2)) {
        p.speed = -p.speed;
    }
}

//===========================================================================
void Background::update() {
    for (uint8_t i = 0; i < BACKGROUND_PARTICLE_COUNT; ++i) {
        updateParticle(particles[i]);
    }
}

//===========================================================================
void Background::updateParticle(Particle& p) const {
    if ((p.x < 0) || (p.x >= WIDTH)) {
        p.y = random(HEIGHT);
    }
    p.x = (p.x % WIDTH) + p.speed;
}

//===========================================================================
void Background::draw() const {
    for (uint8_t i = 0; i < BACKGROUND_PARTICLE_COUNT; ++i) {
        drawParticle(particles[i]);
    }
}

//===========================================================================
void Background::drawParticle(const Particle& p) const {
    int8_t x = p.x;
    for (uint8_t i = 0; i < abs(p.speed); ++i) {
        arduboy.drawPixel(x, p.y, WHITE);
        if (p.speed > 0) {
            --x;
        } else {
            ++x;
        }
    }
}

//===========================================================================
