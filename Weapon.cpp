#include "Weapon.h"
#include<iostream>
void Weapon::setTexture(const std::string& texturePath)
{
    //wczytywanie tekstury broni
    if (!m_texture.loadFromFile(texturePath))
    {
        // Obs³uga b³êdu ³adowania tekstury broni
    }
    m_sprite.setTexture(m_texture);//ustawienie tekstury
    //obracanie tekstury podczas zmiany broni
    if (m_isMovingLeft) {
        m_sprite.setScale(-2.5, 2.5);
        weapontipposition.x = m_sprite.getPosition().x - m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;
    }
    if (m_isMovingRight){
        m_sprite.setScale(2.5, 2.5);
        weapontipposition.x = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;
    }
}
//ustawia pozycje broni
void Weapon::setPosition(float x, float y)
{
    m_position.x = x; 
    m_position.y = y;
}
//aktualizuje pozycje broni
void Weapon::updatePosition(const sf::Vector2f& championPosition)
{
    m_sprite.setPosition(championPosition.x, championPosition.y);
}
//wyswietla bron na ekran
void Weapon::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}
//ustawia parametry broni które s¹ takie same jak bohatera
Weapon::Weapon() : m_movementSpeed(200.0f), m_isMovingLeft(false), m_isMovingRight(false)
{
    //powieksza bron
    m_sprite.setScale(2.5, 2.5);
}
//zmienia predkosc na podan¹ w konstruktorze
void Weapon::setMovementSpeed(float speed)
{
    m_movementSpeed = speed;
}

void Weapon::update(float deltaTime)//zmiana pozycji wzgledem up³ywu czasu
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
//ustawianie pozycji czubka broni
void Weapon::settipPosition(float x,float y) {
    weapontipposition.x = x;
    weapontipposition.y = y;
}
void Weapon::handleInput(sf::Keyboard::Key key, bool isPressed)
{//zmiana pozycji czubka broni i obrot broni w zaleznosci od kierunku poruszania siê
    if (key == sf::Keyboard::A)
    {
        m_isMovingLeft = isPressed;
        if (m_isMovingLeft) {
            m_sprite.setScale(-2.5f, 2.5f);
        }
        weapontipposition.x = m_sprite.getPosition().x-m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;


    }
    else if (key == sf::Keyboard::D)
    {
        m_isMovingRight = isPressed;
        if (m_isMovingRight) {
            m_sprite.setScale(2.5f, 2.5f); // Resetowanie skali (brak obrotu)
        }
        weapontipposition.x = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width;
        weapontipposition.y = m_sprite.getPosition().y + m_sprite.getGlobalBounds().height / 2;
    }
}
//zwraca polozenia czubka broni
sf::Vector2f Weapon::gettipPosition() {
    return weapontipposition;
}