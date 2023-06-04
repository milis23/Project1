#ifndef AID_H
#define AID_H

#include "AnimowaneAssety.h"

class Aid : public AnimowaneAssety
{
public:
    Aid(float startX, float startY, float speedx, float speedy);

protected:
    virtual void collide(Assety& col);
    void handleCollision(sf::RenderWindow& window) override;
};

#endif // AID_H