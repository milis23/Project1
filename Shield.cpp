#include "Shield.h"

Shield::Shield(float startX, float startY, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla tarczy
    if (!m_texture.loadFromFile("shield.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY);//ustawienie pozycji pocz¹tkowej
    m_sprite.setTexture(m_texture);//ustawienie tekstury
    m_velocity.x = speedx;//ustawienie predkosci x
    m_velocity.y = speedy;//ustawienie predkosci y
    // Dodatkowe konfiguracje sprite'a dla bomby
}
void Shield::handleCollision(sf::RenderWindow& window)
{
    //wyzerowanie predkosci po spotkaniu z pod³og¹
    if (m_sprite.getPosition().y > 915) {
        m_velocity.y = 0;
    }
}