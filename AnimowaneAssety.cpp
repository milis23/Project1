#include "AnimowaneAssety.h"

AnimowaneAssety::AnimowaneAssety(float startX, float startY, float speedx,float speedy)
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
sf::FloatRect AnimowaneAssety::getGlobalBounds()//zwraca GlobalBounds obiektu
{
    return sf::FloatRect(m_position.x, m_position.y, m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}
void AnimowaneAssety::update(float deltaTime)
{
    // Aktualizacja pozycji na podstawie prêdkoœci i up³ywu czasu
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
