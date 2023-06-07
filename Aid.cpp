#include "Aid.h"

Aid::Aid(float startX, float startY, float speedx,float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
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


void Aid::handleCollision(sf::RenderWindow& window)
{
    // Obs?uga kolizji dla pomocy
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
    if (m_sprite.getPosition().y > 928) {
        m_velocity.y = 0;
    }
}
