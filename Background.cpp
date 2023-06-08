#include "Background.h"

Background::Background()
{
}

bool Background::loadTexture(const std::string& imagePath)
{
    //wczytywanie tekstury t³a
    if (!texture.loadFromFile(imagePath))
    {
        std::cout << "blad wczytywanie tekstury t³a" << std::endl;
        return false;
    }
    //ustawianie t³a
    sprite.setTexture(texture);
    return true;
}
//wyswietlanie tla
void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}