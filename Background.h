#ifndef BACKGROUND_H
#define BACKGROUND_H
#include<iostream>
#include <SFML/Graphics.hpp>

class Background : public sf::Sprite
{
public:
    Background();

    bool loadTexture(const std::string& imagePath);//wczytywanie tekstury
    void draw(sf::RenderWindow& window);//rysowanie t³a

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // BACKGROUND_H