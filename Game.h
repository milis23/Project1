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
class Game
{
public:
    Game();
    ~Game();
    void run();

    int framecounter = 0;

private:
    bool moved = false;
    sf::RenderWindow window;
    Background background;
    Champion champion;
    Weapon weapon;
    sf::Clock clock;
    float spawnTimer=0;
    float spawnInterval = 1;
    sf::Vector2f mousePosition;
    sf::Vector2f normalizategunmouse;
    std::vector<AnimowaneAssety*> assets;
    std::vector<AnimowaneAssety*> bullets;
    void spawnAsset();
    void processEvents();
    void update(float deltaTime);
    void render();
    void checkCollisions();
    void setAlive(bool ali);
};

#endif // GAME_H