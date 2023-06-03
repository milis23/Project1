#ifndef BULLET_H
#define BULLET_H
#include"AnimowaneAssety.h"
#include <SFML/Graphics.hpp>

class Bullet :public AnimowaneAssety
{
public:
    Bullet(float startX, float startY, float speedx, float speedy);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    bool isOutOfBounds(const sf::RenderWindow& window) const;
    sf::FloatRect getGlobalBounds() const;
protected:
    virtual void collide(AnimowaneAssety& col);
    void handleCollision(sf::RenderWindow& window) override;
private:
};

#endif // BULLET_H

