#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include"AnimowaneAssety.h"
class Champion :public sf::Sprite
{
public:
    Champion();
    void setPosition(float x, float y);
    void setTexture(const std::string& texturePath);
    void setMovementSpeed(float speed);
    void setWeaponOffset(float offsetX, float offsetY);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Keyboard::Key key, bool isPressed);
    void livesplus();
    void livesminus();
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    float m_movementSpeed;
    Weapon m_weapon;

    int lives = 3;
    bool m_isMovingLeft;
    bool m_isMovingRight;
};