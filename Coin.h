#ifndef COIN_H
#define COIN_H

#include "AnimowaneAssety.h"

class Coin : public AnimowaneAssety
{
public:
    Coin(float startX, float startY, float speedx, float speedy);

protected:
    //wykrywanie zderzenia z podloga
    void handleCollision(sf::RenderWindow& window) override;

};

#endif // COIN_H