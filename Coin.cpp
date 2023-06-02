#include "Coin.h"

Coin::Coin(float startX, float startY, float angle, float speed)
    : AnimowaneAssety(startX, startY, angle, speed)
{
    // Inicjalizacja sprite'a i tekstury dla monety
    if (!m_texture.loadFromFile("bomba.png"))
    {
        // Obs�uga b��du �adowania tekstury dla bomby
    }

    m_sprite.setTexture(m_texture);
    // Dodatkowe konfiguracje sprite'a dla bomby
}

void Coin::handleCollision()
{
    // Obs�uga kolizji dla monety
    // Mo�esz doda� tu odpowiednie akcje w przypadku kolizji
}