#include "Bomb.h"

Bomb::Bomb(float startX, float startY, float angle, float speedx,float speedy)
    : AnimowaneAssety(startX, startY, angle, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla bomby
    if (!m_texture.loadFromFile("bomb.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Bomb::handleCollision()
{
    // Obs?uga kolizji dla bomby
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
}