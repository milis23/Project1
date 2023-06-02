#include "Game.h"

Game::Game() : window(sf::VideoMode(1920, 1080), "ShooterGame", sf::Style::Fullscreen)
{
    if (!background.loadTexture("background.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury t³a
    }

    champion.setTexture("champion1.png");
    champion.setScale(champion.getScale().x/30,champion.getScale().y/30);
    weapon.setTexture("weapon.png");
    champion.setPosition(window.getSize().x/2, 905.f);
    champion.setMovementSpeed(200.0f);
    weapon.setPosition(window.getSize().x / 2, 905.f);
}

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime.asSeconds());
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
            else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
            {
                champion.handleInput(event.key.code, true);
                weapon.handleInput(event.key.code, true);
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
            {
                champion.handleInput(event.key.code, false);
                weapon.handleInput(event.key.code, false);
            }
        }
    }
}

void Game::update(float deltaTime)
{
    champion.update(deltaTime);
    weapon.update(deltaTime);
}

void Game::render()
{
    window.clear();
    background.draw(window);
    champion.draw(window);
    weapon.draw(window);
    window.display();
}