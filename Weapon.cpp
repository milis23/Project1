#include "Weapon.h"

void Weapon::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury broni
    }

    m_sprite.setTexture(m_texture);
    m_sprite.setScale(2.5, 2.5);
}

void Weapon::setPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
}

void Weapon::updatePosition(const sf::Vector2f& championPosition)
{
    m_sprite.setPosition(championPosition.x, championPosition.y);
}

void Weapon::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
Weapon::Weapon() : m_movementSpeed(200.0f), m_isMovingLeft(false), m_isMovingRight(false)
{
}

void Weapon::setMovementSpeed(float speed)
{
    m_movementSpeed = speed;
}

void Weapon::update(float deltaTime)
{
    // Poruszanie siê bohatera w zale¿noœci od wciœniêtych klawiszy
    if (m_isMovingLeft)
    {
        m_position.x -= m_movementSpeed * deltaTime;

    }
    else if (m_isMovingRight)
    {
        m_position.x += m_movementSpeed * deltaTime;
    }

    // Aktualizacja pozycji bohatera i broni
    m_sprite.setPosition(m_position);

}

void Weapon::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::A)
    {
        m_isMovingLeft = isPressed;
        m_sprite.setScale(-2.5f, 2.5f);
    }
    else if (key == sf::Keyboard::D)
    {
        m_isMovingRight = isPressed;
        m_sprite.setScale(2.5f, 2.5f); // Resetowanie skali (brak obrotu)
    }
}