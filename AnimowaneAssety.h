#ifndef ANIMOWANEASSETY_H
#define ANIMOWANEASSETY_H

#include"AnimowaneAssety.h"
#include <SFML/Graphics.hpp>
#include <random>
#include"Assety.h"
class AnimowaneAssety: public Assety
{
public:
    AnimowaneAssety(float startX, float startY, float speedx,float speedy);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    virtual void collide(Assety& col) = 0;
    sf::Vector2f getPosition() const;
    void changevelocityx(float speedx);
    void changevelocityy(float speedy);
protected:
    
    sf::RenderWindow m_window;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;
    double acceleration = -1.1;
    virtual void handleCollision(sf::RenderWindow& window) = 0;
};

#endif // ANIMOWANEASSETY_H