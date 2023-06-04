#include "Coin.h"

Coin::Coin(float startX, float startY, float speedx, float speedy)
    : AnimowaneAssety(startX, startY, speedx,speedy)
{
    // Inicjalizacja sprite'a i tekstury dla monety
    if (!m_texture.loadFromFile("coin.png"))
    {
        // Obs?uga b??du ?adowania tekstury dla bomby
    }
    ObjectType type = ObjectType::COIN;
    m_sprite.setPosition(startX, startY);
    m_sprite.setTexture(m_texture);
    m_velocity.x = speedx;
    m_velocity.y = speedy;
    // Dodatkowe konfiguracje sprite'a dla bomby
}
void Coin::collide(Assety& col) {
    if (col.type == ObjectType::CHAMPION) {
        std::cout << "KOLIZJA COIN CHAMPION" << std::endl;
        this->alive = false;
    }
    if (col.type == ObjectType::BULLET) {
        this->alive = false;
        std::cout << "KOLIZJA COIN BULLET" << std::endl;
    }
    if (col.type == ObjectType::NET) {
        this->alive = false;
        std::cout << "KOLIZJA COIN BULLET" << std::endl;
    }
}
void Coin::handleCollision(sf::RenderWindow& window)
{
    // Obs?uga kolizji dla monety
    // Mo?esz doda? tu odpowiednie akcje w przypadku kolizji
    if (m_sprite.getPosition().y > 915) {
        m_velocity.y = 0;
    }
}