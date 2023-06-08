#pragma once

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include"AnimowaneAssety.h"
class Champion :public sf::Sprite
{
public:
    Champion();
    void setPosition(float x, float y);//metoda rozszerzona o pola dotycz¹ce broni wzglêdem tej dziedziczonej
    void setTexture(const std::string& texturePath);//ustawianie tekstury wraz z wartoœciami pocz¹tkowymi obiektu
    void changetexture(const std::string& texturePath);//ustawienie tekstury
    void setMovementSpeed(float speed);//ustawienie predkosci poziomej gracza
    void update(float deltaTime);//zmiana polozenia wzgledem czasu i predkosci
    void draw(sf::RenderWindow& window);//wyswietlanie na ekran
    void handleInput(sf::Keyboard::Key key, bool isPressed);//obrót tekstur wzgledem kierunku poruszania
    void livesplus();//dodaje zycia
    void livesminus();//odejmuje zycie
    int getlives();//zwraca zycia
    int getpoints();//zwraca punkty
    void setimmortal(bool immo);//ustawia zmienn¹ niesmiertelnosci
    bool getimmortal();//zwraca niesmiertelnosc
    void pointsplus();//dodaje 10 punktow
    void pointsminus();//odajemuje 10 punktow
    bool getmovingleft();//zwraca zmienna ismovingleft
    sf::FloatRect getGlobalBounds() const;//zwraca Globalbounds obiektu
private:
    sf::Texture m_texture;//tekstura obiektu
    sf::Sprite m_sprite;//obiekt
    sf::Vector2f m_position;//pozycja obiektu
    sf::RenderWindow m_window;//okno
    float m_movementSpeed;//predkosc poruszania
    Weapon m_weapon;//bron
    int points = 0;//inicjacja punktow
    int lives = 3;//inicjacja zyc
    bool immortal = false;//niesmiertelnosc =false poniewaz nie zebrano jeszcze tarczy
    bool m_isMovingLeft;//zmienne aby odpowiednio scalowac tekstury
    bool m_isMovingRight;
};