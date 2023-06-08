#ifndef BOMB_H
#define BOMB_H

#include "AnimowaneAssety.h"

class Bomb : public AnimowaneAssety
{
public:
    Bomb(float startX, float startY, float speedx, float speedy);

protected:
    int maxspeed = 700;//maksymalna predkosc bomby
    void handleCollision(sf::RenderWindow& window) override;//odbijanie sie bomb od scian 
};

#endif // AID_H