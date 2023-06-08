#include "Net.h"
#include<iostream>
Net::Net(float startX, float startY, float speedx, float speedy, float degress) :AnimowaneAssety(startX, startY, speedx, speedy) {
    //wczytywanie tekstury pocisku typu net
    if (!m_texture.loadFromFile("net.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury pocisku
    }
    //ustawianie pochodzenia na srodek
    m_position.x = startX; m_position.y = startY;//wczytywanie pozycji poczatkowej
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setTexture(m_texture);//ustawianie tekstury
    m_sprite.setRotation(degress);//ustawianie nachylenia
    m_sprite.setPosition(m_position.x, m_position.y);//ustawianie pozycji poczatkowej 
    // Ustalanie prêdkoœci pocisku w zale¿noœci od kierunku
    m_velocity.x = speedx;
    m_velocity.y = speedy;

}
//poruszanie wzgledem czasu
void Net::update(float deltaTime)
{
    sf::Vector2f displacement = m_velocity * deltaTime;
    m_sprite.move(displacement);
}

void Net::handleCollision(sf::RenderWindow& window) {
    //przedefiniowanie metody abstrakcyjnej
}
sf::FloatRect Net::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}