#ifndef WEAPON_H
#define WEAPON_H
#include <SFML/Graphics.hpp>

class Weapon :public sf::Sprite
{
public:
    Weapon();

    void setTexture(const std::string& texturePath);//ustawia teksture
    void setPosition(float x, float y);//ustawia pozycje
    void updatePosition(const sf::Vector2f& championPosition);//aktualizuje pozycje
    void setMovementSpeed(float speed);//ustawia predkosc poruszania sie
    void update(float deltaTime);//aktualizacja pozycji wzgledem uplywu czasu
    void draw(sf::RenderWindow& window);//rysowanie obiektu
    void handleInput(sf::Keyboard::Key key, bool isPressed);//metoda odpowiada za obrót tekstury
    sf::Vector2f gettipPosition();//zwraca polozenie czubka broni
    void settipPosition(float x,float y);//ustawia polozenia czubka broni
private:
    sf::Vector2f weapontipposition;//pozycje czubka broni
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    bool m_isMovingLeft;//zmienna do ustawiania setScale()
    bool m_isMovingRight;//zmienna do ustawiania setScale()
    float m_movementSpeed;//zmienna predkosci 
    sf::Vector2f m_position;//przechowuje pozycje broni
};

#endif // WEAPON_H