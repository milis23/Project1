#include "net.h"
#include<iostream>
Net::Net(float startX, float startY, float speedx, float speedy, float degress) :AnimowaneAssety(startX, startY, speedx, speedy) {
    if (!m_texture.loadFromFile("net.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury pocisku
    }
    m_sprite.setScale(0.15, 0.15);
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setTexture(m_texture);
    m_sprite.setRotation(degress + 45);
    m_sprite.setPosition(m_position.x, m_position.y - 0);
    std::cout << m_position.x << std::endl;
    // Ustalanie prêdkoœci pocisku w zale¿noœci od kierunku
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

void Net::update(float deltaTime)
{
    sf::Vector2f displacement = m_velocity * deltaTime;
    m_sprite.move(displacement);
}

void Net::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

bool Net::isOutOfBounds(const sf::RenderWindow& window) const
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    return (bounds.left + bounds.width < 0.0f || bounds.left > window.getSize().x ||
        bounds.top + bounds.height < 0.0f || bounds.top > window.getSize().y);
}
void Net::collide(AnimowaneAssety& col) {

}
void Net::handleCollision(sf::RenderWindow& window) {

}
sf::FloatRect Net::getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}