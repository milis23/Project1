#ifndef AID_H
#define AID_H

#include "AnimowaneAssety.h"

class Aid : public AnimowaneAssety
{
public:
    Aid(float startX, float startY, float speedx, float speedy);//konstruktor apteczki
protected:
    void handleCollision(sf::RenderWindow& window) override;//wyzerowanie predkosci przy zderzeniu z podlog¹

};

#endif // AID_H