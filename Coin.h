#ifndef COIN_H
#define COIN_H

#include "AnimowaneAssety.h"

class Coin : public AnimowaneAssety
{
public:
    Coin(float startX, float startY, float angle, float speed);

protected:
    void handleCollision() override;
};

#endif // COIN_H

