#include "Hearts.h"
Hearts::Hearts(float x,float y)
{
    //wczytywanie tekstury
    if (!m_texture.loadFromFile("heart.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    //ustawianie pozycji
    m_sprite.setPosition(x, y);
    //ustawianie tekstury
    m_sprite.setTexture(m_texture);
}
//rysowanie na ekran
void Hearts::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}