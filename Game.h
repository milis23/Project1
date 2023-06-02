#ifndef GAME_H
#define GAME_H
#include"Bomb.h"
#include"Coin.h"
#include"Aid.h"
#include"Shield.h"
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Champion.h"

class Game
{
public:
    Game();

    void run();

private:
    sf::RenderWindow window;
    Background background;
    Champion champion;
    Weapon weapon;
    
    void processEvents();
    void update(float deltaTime);
    void render();
    std::vector<std::unique_ptr<AnimowaneAssety>> obiekty;
    sf::Clock clock;
    float spawnTimer;
    float spawnInterval;
    std::mt19937 generator;
    std::uniform_real_distribution<float> xPosDistribution;
    std::uniform_real_distribution<float> angleDistribution;
    std::uniform_real_distribution<float> speedDistribution;

};

#endif // GAME_H