#include "Bullet.h"
#include<iostream>
Bullet::Bullet(float startX, float startY, float speedx, float speedy, float degress):AnimowaneAssety(startX, startY, speedx, speedy) {
    //wczytywanie tekstury pocisku
    if (!m_texture.loadFromFile("bullet.png"))
    {
        // Obs�uga b��du �adowania tekstury pocisku
    }
    //ustawienie pochodzenia na srodek
    m_position.x = startX; m_position.y = startY;//ustawienie pozycji poczatkowej
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2, m_sprite.getGlobalBounds().height/2);
    m_sprite.setTexture(m_texture);//ustawienie tekstury
    m_sprite.setRotation(degress);//ustawienie nachylenia
    m_sprite.setPosition(m_position.x,m_position.y);//ustawienie pozycji poczatkowej
    // Ustalanie pr�dko�ci pocisku w zale�no�ci od kierunku
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

//zmiana pozycji wzgledem czasu
void Bullet::update(float deltaTime)
{
    sf::Vector2f displacement = m_velocity * deltaTime;
    m_sprite.move(displacement);

}
void Bullet::handleCollision(sf::RenderWindow& window)
{
    //przedefiniowanie metody abstrakcyjnej
}

//zwraca GlobalBounds obiektu
sf::FloatRect Bullet::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}