#ifndef NET_H
#define NET_H
#include"AnimowaneAssety.h"
#include <SFML/Graphics.hpp>

class Net :public AnimowaneAssety
{
public:
    Net(float startX, float startY, float speedx, float speedy, float degres);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    bool isOutOfBounds(const sf::RenderWindow& window) const;
    sf::FloatRect getGlobalBounds() const;
protected:
    virtual void collide(Assety& col);
    void handleCollision(sf::RenderWindow& window) override;

private:
};

#endif // NET_H