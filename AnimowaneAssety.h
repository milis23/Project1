#ifndef ANIMOWANEASSETY_H
#define ANIMOWANEASSETY_H

#include <SFML/Graphics.hpp>
#include <random>
class AnimowaneAssety: public sf::Sprite
{
public:
    AnimowaneAssety(float startX, float startY, float speedx,float speedy);

    void update(float deltaTime);//zmiana pozycji obiektow
    void draw(sf::RenderWindow& window);//rysowanie obiekt
    void changevelocityx(float speedx);//zmiana predkosci x
    void changevelocityy(float speedy);//zmiana predkosci y
    sf::FloatRect getGlobalBounds();//zwraca GlobalBounds obiektu
    bool alive = true;//zmienna do okreslenia czy dany obiekt zyje
protected:
    sf::RenderWindow m_window;
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    sf::Vector2f m_position;//pozycja obiektów
    sf::Vector2f m_velocity;//predkosc obietków
    double acceleration = -1.1;//zmienna przyspieszenia wykorzystywana tylko w bombie ,
    //mozna by j¹ przenieœc do bomb ale moze zostaw wykorzystana rowniez w innych obiektach podczas drobnych przerobek
    virtual void handleCollision(sf::RenderWindow& window) = 0;//wykrywanie kolizji polozenia na ekranie
};

#endif // ANIMOWANEASSETY_H