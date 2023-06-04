#include "Shield.h"

Shield::Shield(float startX, float startY, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla tarczy
    if (!m_texture.loadFromFile("shield.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    ObjectType type = ObjectType::SHIELD;
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}
sf::FloatRect Shield::getBounds() const
{
    return this->getGlobalBounds();
}
void Shield::handleCollision(sf::RenderWindow& window)
{
    // Obs?uga kolizji dla tarczy
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
    if (m_sprite.getPosition().y > 915) {
        m_velocity.y = 0;
    }
}