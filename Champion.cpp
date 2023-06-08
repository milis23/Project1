#include "Champion.h"

Champion::Champion() : m_movementSpeed(200.0f), m_isMovingLeft(false), m_isMovingRight(false)
{
    //ustawia predkosc i zmienne moving left i right na false poniewaz jeszcze sie nie poruszylismy 
}

void Champion::setPosition(float x, float y)
{
    //wczytanie zmiennych do pozycji bohatera
    m_position.x = x;
    m_position.y = y;
    m_sprite.setPosition(m_position);//ustawienie pozycji bohatera
    m_sprite.setScale(m_sprite.getScale().x * 3, m_sprite.getScale().y * 3);//powiekszenie bohatera
    m_weapon.updatePosition(m_position);//zmiana pozycji broni

}
bool Champion::getmovingleft() {
    return m_isMovingLeft;
}//zwraca zmienn¹ bool 
void Champion::setTexture(const std::string& texturePath)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury bohatera
    }
    //ustawia teksture
    m_sprite.setTexture(m_texture);
    // Ustawienie pochodzenia na œrodek tekstury
    m_sprite.setOrigin(m_sprite.getLocalBounds().left + m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().top + m_sprite.getLocalBounds().height / 2);
}
void Champion::setMovementSpeed(float speed)
{//zmiana predkosci
    m_movementSpeed = speed;
}

void Champion::update(float deltaTime)
{
    // zmiana pozycji bohatera w zale¿noœci od kierunku
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
{//zwraca GlobalBounds obiektu
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
    //zmiana tekstury
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