#ifndef BOMB_H
#define BOMB_H

#include "AnimowaneAssety.h"

class Bomb : public AnimowaneAssety
{
public:
    Bomb(float startX, float startY, float speedx, float speedy);

protected:

    void handleCollision(sf::RenderWindow& window) override;
};

#endif // AID_H