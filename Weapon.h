#pragma once

#include <SFML/Graphics.hpp>

class Weapon
{
public:
    Weapon();
    void setPosition(float x, float y);
    void setTexture(const std::string& texturePath);
    void setOffset(float offsetX, float offsetY);
    void updatePosition(const sf::Vector2f& championPosition);
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    float m_offsetX;
    float m_offsetY;
};