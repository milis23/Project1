#ifndef COIN_H
#define COIN_H

#include "AnimowaneAssety.h"

class Coin : public AnimowaneAssety
{
public:
    Coin(float startX, float startY, float speedx, float speedy);

protected:
    void handleCollision(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const;
};

#endif // COIN_H