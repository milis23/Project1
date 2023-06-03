#include "Aid.h"

Aid::Aid(float startX, float startY, float angle, float speedx,float speedy)
    : AnimowaneAssety(startX, startY, angle, speedx,speedy)
{
    if (!m_texture.loadFromFile("hearth.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

void Aid::handleCollision()
{
    // Obs?uga kolizji dla pomocy
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
}
