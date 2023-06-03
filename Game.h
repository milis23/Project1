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
    std::vector<std::unique_ptr<AnimowaneAssety>> obiekty;
    std::vector<AnimowaneAssety*> assets;
    sf::Clock clock;
    float spawnTimer=0;
    float spawnInterval=3;
    std::mt19937 generator;
    std::uniform_real_distribution<float> xPosDistribution;
    std::uniform_real_distribution<float> angleDistribution;
    std::uniform_real_distribution<float> speedDistribution;
    void spawnAsset();
    void processEvents();
    void update(float deltaTime);
    void render();
};

#endif // GAME_H