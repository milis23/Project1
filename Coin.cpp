#include "Coin.h"

Coin::Coin(float startX, float startY, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla monety
    if (!m_texture.loadFromFile("coin.png"))
    {
        // Obsluga bledu ladowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY);    //ustawianie pozycji pocz¹tkowej
    m_sprite.setTexture(m_texture);//wczytywanie tekstury
    m_velocity.x = speedx;//ustawianie predkosci x 
    m_velocity.y = speedy;//ustawianie predkosci y
    // Dodatkowe konfiguracje sprite'a dla bomby
}
void Coin::handleCollision(sf::RenderWindow& window)
{
    // Obs?uga kolizji dla monety
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
    if (m_sprite.getPosition().y > 915) {
        m_velocity.y = 0;
    }
}