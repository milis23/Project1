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

class Game
{
public:
    Game();

    void run();

    int framecounter = 0;

private:
    sf::RenderWindow window;
    Background background;
    Champion champion;
    Weapon weapon;
    sf::Clock clock;
    float spawnTimer;
    float spawnInterval = 1;
    std::mt19937 generator;
    sf::Vector2f mousePosition;
    sf::Vector2f normalizategunmouse;
    std::vector<AnimowaneAssety*> assets;
    std::vector<Bullet*>bullets;
    std::uniform_real_distribution<float> xPosDistribution;
    std::uniform_real_distribution<float> angleDistribution;
    std::uniform_real_distribution<float> speedDistribution;
    void spawnAsset();
    void processEvents();
    void update(float deltaTime);
    void render();
};

#endif // GAME_H