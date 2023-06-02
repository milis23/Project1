#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background
{
public:
    Background();

    bool loadTexture(const std::string& imagePath);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // BACKGROUND_H