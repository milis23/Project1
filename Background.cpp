#include "Background.h"

Background::Background()
{
}

bool Background::loadTexture(const std::string& imagePath)
{
    if (!texture.loadFromFile(imagePath))
    {
        // Obs³uga b³êdu ³adowania tekstury
        return false;
    }

    sprite.setTexture(texture);
    return true;
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}