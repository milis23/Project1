#ifndef GAME_H
#define GAME_H
#include "Bomb.h"
#include "Coin.h"
#include "Shield.h"
#include "Aid.h"
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Champion.h"
#include<iostream>
#include"Bullet.h"
#include<Windows.h>
#include<cmath>
#include"Net.h"
#include<string>
#include"Hearts.h"
class Game
{
public:
    Game();
    ~Game();
    void run();
    int framecounter = 0;
    sf::Vector2f scale;
private:
    void setfonts();//ustawia teksty
    bool moved = false;//zmienna aby rozpoczac gre dopiero po poruszeniu gracza
    sf::RenderWindow window;//inicjalizacja okna
    Background background;//inicjalizacja t�a
    Champion champion;//inicjalizacja bohatera
    Weapon weapon;//inicjalizacja broni
    sf::Font font;//inicjalizacja czcionki
    sf::Text text;;//inicjalizacja text�w
    sf::Text text2;
    sf::Text text3;
    sf::Clock clock;;//inicjalizacja zmiennej czasu
    float spawnTimer=0;//wartosc ktora przechowuje ile czasu up�yne�o od poprzedniego pojawienia sie obiektu
    float spawnInterval = 1;//zmienna parametryzuj�ca czestotliwo�� wypadania obiekt�w
    sf::Vector2f mousePosition;//przechowuje pozyzcje myszki
    sf::Vector2f normalizategunmouse;//przechowuje znormalizowany wektor polozenia myszki wzgledem broni
    std::vector<sf::Text*>texts;//vektor na teksty
    std::vector<Hearts*> hearts;//vektor na zycia
    std::vector<AnimowaneAssety*> assets;//vektor na assety
    std::vector<AnimowaneAssety*> bullets;//vektor na pociski
    void spawnAsset();//metoda spawnuj�ca assety
    void processEvents();//metoda wychwytujaca zdarzenia i wywolujaca nastepne zadania
    void update(float deltaTime);//metoda ktora aktualizauje obiekty wzgledem czasu
    void render();//metoda wyswietlajaca na ekran obiekty
    void checkCollisions();//metoda wykrywajaca kolizje miedzy obiektami
};

#endif // GAME_H