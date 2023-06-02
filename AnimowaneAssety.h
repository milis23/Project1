#ifndef ANIMOWANEASSETY_H
#define ANIMOWANEASSETY_H

#include <SFML/Graphics.hpp>
#include <random>

class AnimowaneAssety
{
public:
    AnimowaneAssety(float startX, float startY, float angle, float speed);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;

protected:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    float acceleration = 1.02;
    virtual void handleCollision() = 0;
};

#endif // ANIMOWANEASSETY_H