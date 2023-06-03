#ifndef SHIELD_H
#define SHIELD_H

#include "AnimowaneAssety.h"

class Shield : public AnimowaneAssety
{
public:
    Shield(float startX, float startY, float angle, float speedx, float speedy);

protected:
    void handleCollision() override;

};

#endif // SHIELD_H