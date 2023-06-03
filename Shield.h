#ifndef SHIELD_H
#define SHIELD_H

#include "AnimowaneAssety.h"

class Shield : public AnimowaneAssety
{
public:
    Shield(float startX, float startY, float speedx, float speedy);

protected:
    void handleCollision(sf::RenderWindow& window) override;
    virtual void collide(AnimowaneAssety& col);
};

#endif // SHIELD_H