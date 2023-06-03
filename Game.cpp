#include "Game.h"

Game::Game() : window(sf::VideoMode(1920, 1080), "ShooterGame", sf::Style::Fullscreen)
{
    window.setFramerateLimit(60);
    if (!background.loadTexture("background.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury t³a
    }
    std::random_device rd;
    generator = std::mt19937(rd());
    xPosDistribution = std::uniform_real_distribution<float>(50.0f, 750.0f);
    angleDistribution = std::uniform_real_distribution<float>(45.0f, 135.0f);
    speedDistribution = std::uniform_real_distribution<float>(100.0f, 200.0f);
    champion.setTexture("champion1.png");
    champion.setScale(champion.getScale().x/30,champion.getScale().y/30);
    weapon.setTexture("weapon.png");
    champion.setPosition(window.getSize().x/2,905);
    champion.setMovementSpeed(200.0f);
    weapon.setPosition(window.getSize().x /2,905);
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
            if ((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)&&(framecounter%16>7)&&(framecounter%16<16))
                champion.changetexture("bieg1.png");
            else if ((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) && (framecounter % 16 > 0)&&(framecounter%16<8))
                champion.changetexture("bieg2.png");
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
            {
                champion.handleInput(event.key.code, false);
                weapon.handleInput(event.key.code, false);
                champion.changetexture("champion1.png");
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
       
        spawnAsset();
        spawnTimer = 0.0f; // Zresetowanie timera

    }
    for (auto& obiekt : assets)
    {
        obiekt->update(deltaTime);

    }
    // Aktualizacja obiektów
}

void Game::render()
{

    framecounter++;
    window.clear();
    background.draw(window);
    champion.draw(window);
    weapon.draw(window);
    for (auto& obiekt : assets)
    {
        obiekt->draw(window);

    }
    window.display();

}

void Game::spawnAsset()
{
    // Wygeneruj losow¹ pozycjê x na górze ekranu
    float xPos = static_cast<float>(rand() % window.getSize().x);

    // Wygeneruj losow¹ prêdkoœæ x i y
    float xVelocity = static_cast<float>(rand() % 200 - 100);
    float yVelocity = static_cast<float>(rand() % 200 + 100);
    float angle = angleDistribution(generator);
    // Wybierz losowy typ aktywa
    int assetType = rand() % 11; // 0 - Coin, 1 - Shield, 2 - Aid

    // Stwórz aktywo na podstawie wybranego typu
    AnimowaneAssety* newAsset = nullptr;
    if (assetType < 8) {
        newAsset = new Bomb(xPos, 0, angle, xVelocity,yVelocity);
        std::cout << "utworzono bombe" << std::endl;
    }
    else {
        switch (assetType)
        {
        case 8:
            newAsset = new Coin(xPos, 0, angle,0, yVelocity);
            std::cout << "utworzono monete" << std::endl;
            break;
        case 9:
            newAsset = new Shield(xPos, 0, angle,0, yVelocity);
            std::cout << "utworzono tarcze" << std::endl;
            break;
        case 10:
            newAsset = new Aid(xPos, 0, angle,0, yVelocity);
            std::cout << "utworzono apteczke" << std::endl;
            break;
        default:
            break;
        }
    }
    if (newAsset != nullptr)
    {
        // Dodaj nowe aktywo do wektora
        assets.push_back(newAsset);
    }
}