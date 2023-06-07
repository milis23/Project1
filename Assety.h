#pragma once
#include<SFML/Graphics.hpp>
enum class ObjectType {
    BOMB = 0,
    SHIELD,
    COIN,
    AID,
    BULLET,
    NET,
    CHAMPION,
    WEAPON
};
class Assety:public sf::Sprite
{
public:
    ObjectType type;
    bool alive = true;
};

