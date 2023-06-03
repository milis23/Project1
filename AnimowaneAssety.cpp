#include "AnimowaneAssety.h"

AnimowaneAssety::AnimowaneAssety(float startX, float startY, float angle, float speedx,float speedy)
{
    // Inicjalizacja sprite'a, tekstury i pozycji
    // startX i startY - pocz¹tkowe wspó³rzêdne obiektu
    // angle - k¹t spadania
    // speed - prêdkoœæ spadania

    // Ustawienie pozycji pocz¹tkowej
    m_position.x = startX;
    m_position.y = startY;

    // Obliczenie wektora prêdkoœci na podstawie k¹ta i prêdkoœci
    m_velocity.x = speedx;
    m_velocity.y = speedy;
}

void AnimowaneAssety::update(float deltaTime)
{
    // Aktualizacja pozycji na podstawie prêdkoœci
    m_position += m_velocity * deltaTime;
    m_sprite.move(m_velocity * deltaTime);
    // Sprawdzenie kolizji ze œcianami lub innymi obiektami
    handleCollision();
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