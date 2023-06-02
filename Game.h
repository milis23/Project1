#ifndef GAME_H
#define GAME_H

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
};

#endif // GAME_H