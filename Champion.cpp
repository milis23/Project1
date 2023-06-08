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
bool Champion::getmovingleft() {
    return m_isMovingLeft;
}
void Champion::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury bohatera
    }

    m_sprite.setTexture(m_texture);

    // Ustawienie pochodzenia na œrodek tekstury
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    m_sprite.setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
}
void Champion::setMovementSpeed(float speed)
{
    m_movementSpeed = speed;
}

void Champion::update(float deltaTime)
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
    m_weapon.updatePosition(m_position);
}
sf::FloatRect Champion::getGlobalBounds() const
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    bounds.left += getPosition().x;
    bounds.top += getPosition().y;
    return bounds;
}
void Champion::changetexture(const std::string& texturePath) {
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury bohatera
    }

    m_sprite.setTexture(m_texture);

    
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
        m_sprite.setScale(-3.0f, 3.0f); // Obrócenie tekstury w lewo
        m_weapon.setScale(-2.5f, 2.5f);
    }
    else if (key == sf::Keyboard::D)
    {
        m_isMovingRight = isPressed;
        m_sprite.setScale(3.0f, 3.0f); // Resetowanie skali (brak obrotu)
        m_weapon.setScale(2.5f, 2.5f);
    }
}
void Champion::setimmortal(bool immo) {
    this->immortal = immo;
}
bool Champion::getimmortal() {
    return immortal;
}
void Champion::livesminus() {
    lives -= 1;
}

void Champion::livesplus() {
    if(lives<=2)
        lives += 1;

}

int Champion::getlives() {
    return lives;
}
void Champion::pointsminus() {
    points-=10;
}
void Champion::pointsplus() {
    points+=10;
}
int Champion::getpoints() {
    return points;
}