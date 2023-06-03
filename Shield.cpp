#include "Shield.h"

Shield::Shield(float startX, float startY, float angle, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, angle, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla tarczy
    if (!m_texture.loadFromFile("shield.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Shield::handleCollision()
{
    // Obs?uga kolizji dla tarczy
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
}