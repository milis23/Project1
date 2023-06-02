#include "Aid.h"

Aid::Aid(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    if (!m_texture.loadFromFile("aid.png"))
    {
        // Obs�uga b��du �adowania tekstury dla bomby
    }

    m_sprite.setTexture(m_texture);
}

void Aid::handleCollision()
{
    // Obs�uga kolizji dla pomocy
    // Mo�esz doda� tu odpowiednie akcje w przypadku kolizji
}