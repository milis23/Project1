#include "Coin.h"

Coin::Coin(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    // Inicjalizacja sprite'a i tekstury dla monety
    if (!m_texture.loadFromFile("bomba.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury dla bomby
    }

    m_sprite.setTexture(m_texture);
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Coin::handleCollision()
{
    // Obs³uga kolizji dla monety
    // Mo¿esz dodaæ tu odpowiednie akcje w przypadku kolizji
}