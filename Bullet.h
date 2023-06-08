#ifndef BULLET_H
#define BULLET_H
#include"AnimowaneAssety.h"
#include <SFML/Graphics.hpp>

class Bullet :public AnimowaneAssety
{
public:
    Bullet(float startX, float startY, float speedx, float speedy,float degres);
    void update(float deltaTime);//aktualizacja pozycji wzgledem czasu
    sf::FloatRect getGlobalBounds() const;//zwraca globalBounds obiektu
protected:
    void handleCollision(sf::RenderWindow& window) override;//przedefiniowanie metody abstrakcyjnej

private:
};

#endif // BULLET_H

