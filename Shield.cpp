#include "Shield.h"

Shield::Shield(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    // Inicjalizacja sprite'a i tekstury dla tarczy
    if (!m_texture.loadFromFile("bomba.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury dla bomby
    }

    m_sprite.setTexture(m_texture);
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Shield::handleCollision()
{
    // Obs³uga kolizji dla tarczy
    // Mo¿esz dodaæ tu odpowiednie akcje w przypadku kolizji
}