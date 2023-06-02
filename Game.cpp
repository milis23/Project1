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
    champion.setPosition(window.getSize().x/2,905);
    champion.setMovementSpeed(200.0f);
    weapon.setPosition(window.getSize().x /2,905);
    spawnTimer = (0.0f);
    spawnInterval = (3.0f);
    std::random_device rd;
    generator = std::mt19937(rd());
    xPosDistribution = std::uniform_real_distribution<float>(50.0f, 750.0f);
    angleDistribution = std::uniform_real_distribution<float>(45.0f, 135.0f);
    speedDistribution = std::uniform_real_distribution<float>(100.0f, 200.0f);
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
    spawnTimer += deltaTime;

    // Tworzenie losowych obiektów co 3 sekundy
    if (spawnTimer >= spawnInterval)
    {
        // Wylosowanie typu obiektu
        std::uniform_int_distribution<int> typeDistribution(0, 3); // 4 typy obiektów
        int objectType = typeDistribution(generator);

        // Wylosowanie pozycji i parametrów obiektu
        float xPos = xPosDistribution(generator);
        float angle = angleDistribution(generator);
        float speed = speedDistribution(generator);

        // Dodanie nowego obiektu na podstawie wylosowanego typu
        switch (objectType)
        {
        case 0:
            obiekty.push_back(std::make_unique<Bomb>(xPos, 0.0f, angle, speed));
            break;
        case 1:
            obiekty.push_back(std::make_unique<Coin>(xPos, 0.0f, angle, speed));
            break;
        case 2:
            obiekty.push_back(std::make_unique<Shield>(xPos, 0.0f, angle, speed));
            break;
        case 3:
            obiekty.push_back(std::make_unique<Aid>(xPos, 0.0f, angle, speed));
            break;
        }

        spawnTimer = 0.0f; // Zresetowanie timera
    }

    // Aktualizacja obiektów
    for (auto& obiekt : obiekty)
    {
        obiekt->update(deltaTime);
    }
}

void Game::render()
{
    window.clear();
    background.draw(window);
    champion.draw(window);
    weapon.draw(window);
    window.display();
}