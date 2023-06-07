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
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Keyboard::Key key, bool isPressed);
    void livesplus();
    void livesminus();
    void changetexture(const std::string& texturePath);
    int getlives();
    int getpoints();
    void setimmortal(bool immo);
    bool getimmortal();
    void pointsplus();
    void pointsminus();
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    sf::RenderWindow m_window;
    float m_movementSpeed;
    Weapon m_weapon;
    int points = 0;
    int lives = 3;
    bool immortal = false;
    bool m_isMovingLeft;
    bool m_isMovingRight;
};