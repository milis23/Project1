#include "Bomb.h"

Bomb::Bomb(float startX, float startY, float speedx,float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla bomby
    if (!m_texture.loadFromFile("bomb.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    ObjectType type = ObjectType::BOMB;
    m_sprite.setPosition(startX, startY-m_sprite.getGlobalBounds().width);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}
sf::FloatRect Bomb::getBounds() const
{
    return this->getGlobalBounds();
}
void Bomb::handleCollision(sf::RenderWindow& window)
{
    // Obs?uga kolizji dla bomby
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
    if (m_sprite.getPosition().x < 0) {
        m_velocity.x *= acceleration;
        if (m_velocity.x > 1000) {
            m_velocity.x = 1000;
        }
    }
    if (m_sprite.getPosition().x > 1920-m_sprite.getGlobalBounds().width) {
        m_velocity.x *= acceleration;

        if (m_velocity.x < -1000) {
            m_velocity.x = -1000;
        }
    }

    if (m_sprite.getPosition().y > 915) {
        m_velocity.y *= acceleration;
        if (m_velocity.y < -1000) {
            m_velocity.y = -1000;
        }
    }    
    if (m_sprite.getPosition().y < 0) {
        m_velocity.y *= acceleration;
        if (m_velocity.y > 1000) {
            m_velocity.y = 1000;
        }
    }
    
}