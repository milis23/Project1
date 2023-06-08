#include "Background.h"

Background::Background()
{
}

bool Background::loadTexture(const std::string& imagePath)
{
    //wczytywanie tekstury t�a
    if (!texture.loadFromFile(imagePath))
    {
        std::cout << "blad wczytywanie tekstury t�a" << std::endl;
        return false;
    }
    //ustawianie t�a
    sprite.setTexture(texture);
    return true;
}
//wyswietlanie tla
void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}