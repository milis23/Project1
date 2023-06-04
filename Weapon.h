#ifndef WEAPON_H
#define WEAPON_H
#include"Assety.h"
#include <SFML/Graphics.hpp>

class Weapon :public Assety
{
public:
    Weapon();

    void setTexture(const std::string& texturePath);
    void setPosition(float x, float y);
    void updatePosition(const sf::Vector2f& championPosition);
    void setMovementSpeed(float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void handleInput(sf::Keyboard::Key key, bool isPressed);
    sf::Vector2f gettipPosition();
    void settipPosition(float x,float y);

private:
    sf::Vector2f weapontipposition;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    bool m_isMovingLeft;
    bool m_isMovingRight;
    float m_movementSpeed;
    sf::Vector2f m_position;
};

#endif // WEAPON_H