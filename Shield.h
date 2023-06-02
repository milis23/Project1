#ifndef SHIELD_H
#define SHIELD_H

#include "AnimowaneAssety.h"

class Shield : public AnimowaneAssety
{
public:
    Shield(float startX, float startY, float angle, float speed);

protected:
    void handleCollision() override;
};

#endif // SHIELD_H