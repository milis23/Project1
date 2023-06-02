#include "Weapon.h"

Weapon::Weapon() : m_offsetX(50.0f), m_offsetY(20.0f)
{
}

void Weapon::setPosition(float x, float y)
{
    m_sprite.setPosition(x + m_offsetX, y + m_offsetY);
}

void Weapon::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury broni
    }

    m_sprite.setTexture(m_texture);
}

void Weapon::setOffset(float offsetX, float offsetY)
{
    m_offsetX = offsetX;
    m_offsetY = offsetY;
}

void Weapon::updatePosition(const sf::Vector2f& championPosition)
{
    m_sprite.setPosition(championPosition.x + m_offsetX, championPosition.y + m_offsetY);
}

sf::Vector2f Weapon::getPosition()
{
    return m_sprite.getPosition();
}

void Weapon::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}