#include "Background.h"

Background::Background()
{
}

bool Background::loadTexture(const std::string& imagePath)
{
    if (!texture.loadFromFile(imagePath))
    {
        // Obs�uga b��du �adowania tekstury
        return false;
    }

    sprite.setTexture(texture);
    return true;
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}