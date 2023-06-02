#include "Bomb.h"

Bomb::Bomb(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    // Inicjalizacja sprite'a i tekstury dla bomby
    if (!m_texture.loadFromFile("bomb.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury dla bomby
    }
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    // Dodatkowe konfiguracje sprite'a dla bomby
}
void Bomb::handleCollision()
{
    // Obs³uga kolizji dla bomby
    // Mo¿esz dodaæ tu odpowiednie akcje w przypadku kolizji
}
