#include "Aid.h"

Aid::Aid(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    if (!m_texture.loadFromFile("aid.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury dla bomby
    }

    m_sprite.setTexture(m_texture);
}

void Aid::handleCollision()
{
    // Obs³uga kolizji dla pomocy
    // Mo¿esz dodaæ tu odpowiednie akcje w przypadku kolizji
}