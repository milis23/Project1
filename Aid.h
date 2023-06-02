#ifndef AID_H
#define AID_H

#include "AnimowaneAssety.h"

class Aid : public AnimowaneAssety
{
public:
    Aid(float startX, float startY, float angle, float speed);

protected:
    void handleCollision() override;
};

#endif // AID_H

