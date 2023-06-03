#include "Bullet.h"

Bullet::Bullet(float startX, float startY, float speedx, float speedy):AnimowaneAssety(startX, startY, speedx, speedy) {
    if (!m_texture.loadFromFile("bullet.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury pocisku
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);

    // Ustalanie prêdkoœci pocisku w zale¿noœci od kierunku
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

void Bullet::update(float deltaTime)
{
    sf::Vector2f displacement = m_velocity * deltaTime;
    m_sprite.move(displacement);
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

bool Bullet::isOutOfBounds(const sf::RenderWindow& window) const
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    return (bounds.left + bounds.width < 0.0f || bounds.left > window.getSize().x ||
            bounds.top + bounds.height < 0.0f || bounds.top > window.getSize().y);
}
void Bullet::collide(AnimowaneAssety& col) {

}
void Bullet::handleCollision(sf::RenderWindow& window) {

}
sf::FloatRect Bullet::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}