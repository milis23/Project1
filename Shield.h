#ifndef SHIELD_H
#define SHIELD_H

#include "AnimowaneAssety.h"

class Shield : public AnimowaneAssety
{
public:
    Shield(float startX, float startY, float speedx, float speedy);

protected:
    //wykrycie zderzenia z podlog¹
    void handleCollision(sf::RenderWindow& window) override;

};

#endif // SHIELD_H