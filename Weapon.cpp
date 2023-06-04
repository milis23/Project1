#include "Weapon.h"
#include<iostream>
void Weapon::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs�uga b��du �adowania tekstury broni
    }
    weapontipposition.x = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width;
    weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(2.5, 2.5);
    ObjectType type = ObjectType::WEAPON;
    
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
    // Poruszanie si� bohatera w zale�no�ci od wci�ni�tych klawiszy
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
void Weapon::settipPosition(float x,float y) {
    weapontipposition.x = x;
    weapontipposition.y = y;
}
void Weapon::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::A)
    {
        m_isMovingLeft = isPressed;
        m_sprite.setScale(-2.5f, 2.5f);
        weapontipposition.x = m_sprite.getPosition().x-m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;


    }
    else if (key == sf::Keyboard::D)
    {
        m_isMovingRight = isPressed;
        m_sprite.setScale(2.5f, 2.5f); // Resetowanie skali (brak obrotu)
        weapontipposition.x = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;
    }
}
sf::Vector2f Weapon::gettipPosition() {
    return weapontipposition;
}