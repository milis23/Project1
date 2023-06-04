#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
enum class ObjectType {
    BOMB = 0,
    SHIELD,
    COIN,
    AID,
    BULLET,
    NET,
    CHAMPION
};

class Assety:public sf::Sprite
{
public:
    bool alive = true; 
    ObjectType type;
};

