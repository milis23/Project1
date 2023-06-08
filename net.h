#ifndef NET_H
#define NET_H
#include"AnimowaneAssety.h"
#include <SFML/Graphics.hpp>

class Net :public AnimowaneAssety
{
public:
    Net(float startX, float startY, float speedx, float speedy, float degres);
    //aktualizajca pozycji wzgledem czasu
    void update(float deltaTime);
    //zwraca GlobalBounds obiektu
    sf::FloatRect getGlobalBounds() const;
protected:
    void handleCollision(sf::RenderWindow& window) override;//przedefiniowanie metody abstrakcyjnej

private:
};

#endif // NET_H