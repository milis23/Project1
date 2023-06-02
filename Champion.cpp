#include "Champion.h"

Champion::Champion() : m_movementSpeed(200.0f), m_isMovingLeft(false), m_isMovingRight(false)
{
}

void Champion::setPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
    m_sprite.setPosition(m_position);
    m_sprite.setScale(m_sprite.getScale().x * 3, m_sprite.getScale().y * 3);
    m_weapon.updatePosition(m_position);

}

void Champion::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs�uga b��du �adowania tekstury bohatera
    }

    m_sprite.setTexture(m_texture);

    // Ustawienie pochodzenia na �rodek tekstury
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
}
void Champion::setMovementSpeed(float speed)
{
    m_movementSpeed = speed;
}

void Champion::setWeaponOffset(float offsetX, float offsetY)
{
    m_weapon.setOffset(offsetX, offsetY);
}

void Champion::update(float deltaTime)
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
    m_weapon.updatePosition(m_position);
}

void Champion::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
    m_weapon.draw(window);
}

void Champion::handleInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::A)
    {
        m_isMovingLeft = isPressed;
        m_sprite.setScale(-3.0f, 3.0f); // Obr�cenie tekstury w lewo
    }
    else if (key == sf::Keyboard::D)
    {
        m_isMovingRight = isPressed;
        m_sprite.setScale(3.0f, 3.0f); // Resetowanie skali (brak obrotu)
    }
}

void Champion::livesminus() {
    lives -= 1;
}
void Champion::livesplus() {
    lives += 1;
}