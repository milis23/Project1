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
sf::FloatRect AnimowaneAssety::getGlobalBounds()//zwraca GlobalBounds obiektu
{
    return sf::FloatRect(m_position.x, m_position.y, m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}
void AnimowaneAssety::update(float deltaTime)
{
    // Aktualizacja pozycji na podstawie pr�dko�ci i up�ywu czasu
    m_position += m_velocity * deltaTime;
    m_sprite.move(m_velocity * deltaTime);
    handleCollision(m_window);

}
//zmniana prywatnej wartosci predkosci x
void AnimowaneAssety::changevelocityx(float speedx) {
    this->m_velocity.x = speedx;
}
//zmniana prywatnej wartosci predkosci y
void AnimowaneAssety::changevelocityy(float speedy) {
    this->m_velocity.y = speedy;
}
void AnimowaneAssety::draw(sf::RenderWindow& window)
{
    // Narysowanie sprite'a na oknie renderowania
    window.draw(m_sprite);
}
