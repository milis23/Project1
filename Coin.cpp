#include "Coin.h"

Coin::Coin(float startX, float startY, float angle, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, angle, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla monety
    if (!m_texture.loadFromFile("coin.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    setScale(getScale().x/4, getScale().y/4);
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Coin::handleCollision()
{
    // Obs?uga kolizji dla monety
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
}