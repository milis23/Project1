#include "Bomb.h"
#include<iostream>
Bomb::Bomb(float startX, float startY, float speedx,float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla bomby
    if (!m_texture.loadFromFile("bomb.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY-m_sprite.getGlobalBounds().width);//ustawianie pozycji poczatkowej
    m_sprite.setTexture(m_texture);//ustawianie tekstury
    m_velocity.x = speedx;//poczatkowa predkosc x
    m_velocity.y = speedy;//poczatkowa predkosc y
}

void Bomb::handleCollision(sf::RenderWindow& window)
{
    //przyœpieszanie podczas obicia i ograniczenie maksymalnej predkosci aby bomby nie szalal³y za bardzo
    if (m_sprite.getPosition().x < 0) {
        m_velocity.x *= acceleration;
        if (m_velocity.x > maxspeed) {
            m_velocity.x = maxspeed;
        }
    }
    if (m_sprite.getPosition().x > 1920-m_sprite.getGlobalBounds().width) {
        m_velocity.x *= acceleration;

        if (m_velocity.x < -maxspeed) {
            m_velocity.x = -maxspeed;
        }
    }

    if (m_sprite.getPosition().y > 915) {
        m_velocity.y *= acceleration;
        if (m_velocity.y < -maxspeed) {
            m_velocity.y = -maxspeed;
        }
    }    
    if (m_sprite.getPosition().y < 0) {
        m_velocity.y *= acceleration;
        if (m_velocity.y > maxspeed) {
            m_velocity.y = maxspeed;
        }
    }
}