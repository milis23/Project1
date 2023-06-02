#ifndef BOMB_H
#define BOMB_H

#include "AnimowaneAssety.h"

class Bomb : public AnimowaneAssety
{
public:
    Bomb(float startX, float startY, float angle, float speed);

protected:
    void handleCollision() override;
};

#endif // BOMB_H
