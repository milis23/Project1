#include "AnimowaneAssety.h"

AnimowaneAssety::AnimowaneAssety(float startX, float startY, float speedx,float speedy)
{
    // Inicjalizacja sprite'a, tekstury i pozycji
    // startX i startY - pocz�tkowe wsp�rz�dne obiektu
    // angle - k�t spadania
    // speed - pr�dko�� spadania

    // Ustawienie pozycji pocz�tkowej
    m_position.x = startX;
    m_position.y = startY;

    // Obliczenie wektora pr�dko�ci na podstawie k�ta i pr�dko�ci
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

void AnimowaneAssety::update(float deltaTime)
{
    // Aktualizacja pozycji na podstawie pr�dko�ci
    m_position += m_velocity * deltaTime;
    m_sprite.move(m_velocity * deltaTime);

    
    // Sprawdzenie kolizji ze �cianami lub innymi obiektami
    handleCollision(m_window);
}
void AnimowaneAssety::changevelocityx(float speedx) {
    this->m_velocity.x = speedx;
}
void AnimowaneAssety::changevelocityy(float speedy) {
    this->m_velocity.y = speedy;
}
void AnimowaneAssety::draw(sf::RenderWindow& window)
{
    // Narysowanie sprite'a na oknie renderowania
    window.draw(m_sprite);
}

sf::Vector2f AnimowaneAssety::getPosition() const
{
    return m_position;
}