#include "Game.h"

Game::Game() : window(sf::VideoMode(1920, 1080), "ShooterGame", sf::Style::Fullscreen)
{
    window.setFramerateLimit(60);
    //wczytywanie tekstury t³a
    if (!background.loadTexture("background.png"))
    {
        // Obs³uga b³êdu ³adowania tekstury t³a
    }
    //ustawianie bazowej tekstury dla bohatera
    champion.setTexture("champion1.png");
    //ustalanieskali bohatera
    champion.setScale(champion.getScale().x/30,champion.getScale().y/30);
    //wczytywanie tekstury broni
    weapon.setTexture("weapon.png");
    //ustawianie bohatera
    champion.setPosition(static_cast<float>(window.getSize().x/2),static_cast<float>(905));
    champion.setMovementSpeed(200.0f);
    //ustawianie broni
    weapon.setPosition(static_cast<float>(window.getSize().x / 2),static_cast<float>(905));
}

Game::~Game() {
    //usuwanie wskaŸnikow przy zakoñczeniu gry
    for (AnimowaneAssety* wskaznik : assets) {
        delete wskaznik;
        std::cout << "usunieto wskaznik" << std::endl;
    }
    for (AnimowaneAssety* wskaznik : bullets) {
        delete wskaznik;
        std::cout << "usunieto wskaznik" << std::endl;
    }
}

void Game::run()
{
    sf::Clock clock;
    //pêtla gry
    while (window.isOpen())
    {
        //odmierzanie czasu pomiêdzy pêtlami 
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime.asSeconds());
        render();
        //warunki zakoñczenia gry
        if (champion.getpoints() >= 200) {
            std::cout << "WYGRANA" << std::endl;
            break;
        }

        if (champion.getlives() <= 0) {
            std::cout << "PRZEGRANA" << std::endl;
            break;
        }

    }
}
void Game::checkCollisions()
{//sprawdzanie kolizji
    for (AnimowaneAssety* asset:assets) {
        Bomb* bomb = dynamic_cast<Bomb*>(asset);
        Coin* coin = dynamic_cast<Coin*>(asset);
        Shield* shield = dynamic_cast<Shield*>(asset);
        Aid* aid = dynamic_cast<Aid*>(asset);
        for (AnimowaneAssety* bullet:bullets) {
            Bullet* bull = dynamic_cast<Bullet*>(bullet);
            Net* net = dynamic_cast<Net*>(bullet);
                if (asset->getGlobalBounds().intersects(bullet->getGlobalBounds())) {//wykrywanie kolizji bulletów z assetami
                    //zmienna alive po zderzeniu zmieniana jest na false
                    bullet->alive = false;
                    //dynamic casty aby sprawdziæ z jakim obiektem mamy doczynienia
                    
                    
                    
                    if (bull != nullptr) {//jeœli obiek z bullets jest bulletem 
                        asset->alive = false;
                        if (coin != nullptr) {//jeœli obiekt z assetów jest coinem
                            champion.pointsminus();//zniszczenie monety skutkuje zabraniem 20 punktów
                        }
                    }
                    else if(net!=nullptr){
                        asset->alive = false;
                        if (bomb != nullptr && champion.getimmortal() == false) {//jeœli obiekt z assetów jest bomb¹ i nie mamy nieœmiertelnoœci
                            champion.livesminus();//zabieramy ¿ycie
                        }
                        else if (bomb != nullptr && champion.getimmortal() == true) {//jeœli obiekt z assetów jest bomb¹ ale mamy nieœmiertelnoœæ
                            champion.setimmortal(false);//wy³¹czamy nieœmiertelnoœæ
                        }
                        else if (coin != nullptr) {//jeœli obiekt z assetów jest coinem
                            champion.pointsplus();//dodajemy 20 punktów
                        }
                        else if (shield != nullptr) {//jeœli obiekt z assetów jest tarcz¹
                            champion.setimmortal(true);//nieœmiertelnoœæ jest w³¹czona
                        }
                        else if (aid != nullptr) {//jeœli obiekt z assetów jest apteczk¹
                            champion.livesplus();//+1 zycie
                        }
                    }
                }
        }
        if (champion.getGlobalBounds().intersects(asset->getGlobalBounds())) {
            std::cout << "dupa" << std::endl;

        }
    }
}

void Game::processEvents()
{//wykrywanie eventow
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
                //zmienna wykorzystywana w Game::spawnAssets();
                moved = true;
                //obrócenie tekstur
                champion.handleInput(event.key.code, true);
                weapon.handleInput(event.key.code, true);
            }
            if ((event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)) {
                //animacja biegania
                if (((framecounter % 16 > 12) && (framecounter % 16 < 16)) || ((framecounter % 16 > 4) && (framecounter % 16 < 8))) {
                    champion.changetexture("bieg1.png");
                }
                else if (((framecounter % 16 > 8) && (framecounter % 16 < 12)) || ((framecounter % 16 > 0) && (framecounter % 16 < 4))) {
                    champion.changetexture("bieg2.png");
                }
            }
        }
        else if ((event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Right || event.mouseButton.button == sf::Mouse::Left))&&moved==true)
        {
            //pobieranie pozycji myszki aby znormalizowaæ wektor potrzebny do obrócenia tekstur pocisków
            mousePosition.x = static_cast<float>(sf::Mouse::getPosition(window).x);
            mousePosition.y = static_cast<float>(sf::Mouse::getPosition(window).y);
            normalizategunmouse = (mousePosition - weapon.gettipPosition())/sqrt((mousePosition.x - weapon.gettipPosition().x)* (mousePosition.x - weapon.gettipPosition().x) + (mousePosition.y - weapon.gettipPosition().y) * (mousePosition.y - weapon.gettipPosition().y));
            if (event.mouseButton.button == sf::Mouse::Left) {
                //wystrzelenie bulletu z broni
                Bullet* newbullet = nullptr;
                //k¹t nachylenia pocisku 
                float angle = std::atan2(normalizategunmouse.y, normalizategunmouse.x);
                //konwersja z radianów
                float degrees = static_cast<float>(angle * 180 / 3.14159265358979323846);
                //tworzenie pocisku
                newbullet = new Bullet(weapon.gettipPosition().x, weapon.gettipPosition().y, normalizategunmouse.x * 400, normalizategunmouse.y * 400,degrees);
                bullets.emplace_back(newbullet);
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                //tworzenie pocisku typu net
                Net* newnet = nullptr;
                float angle = std::atan2(normalizategunmouse.y, normalizategunmouse.x);
                float degrees = static_cast<float>(angle * 180 / 3.14159265358979323846);
                newnet = new Net(weapon.gettipPosition().x, weapon.gettipPosition().y, normalizategunmouse.x * 400, normalizategunmouse.y * 400, degrees);
                bullets.emplace_back(newnet);
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
            {
                //powrót do tekstury spoczynku i obrócenie tekstur
                champion.handleInput(event.key.code, false);
                weapon.handleInput(event.key.code, false);
                champion.changetexture("champion1.png");
            }
        }  
    }
}

void Game::update(float deltaTime)
{
    //poruszanie sie championa i broni
    champion.update(deltaTime);
    weapon.update(deltaTime);
    //dodawanie up³yniêtego czasu pomiêdzy pêtlami do zmiennej spawnTimer
    spawnTimer += deltaTime;
    // Tworzenie losowych obiektów co 3 sekundy
    if (spawnTimer >= spawnInterval)
    {
       //wywo³anie metody od spawnowania obiektów
        spawnAsset();
        spawnTimer = 0.0f; // Zresetowanie timera

    }
    // Aktualizacja obiektów
    for (auto& obiekt : assets)
    {
        //poruszanie siê assetów
        obiekt->update(deltaTime);
    }
    for (auto& pocisk : bullets)
    {
        //poruszanie siê pocisków
        pocisk->update(deltaTime);


    }
    for (AnimowaneAssety* obiekt : bullets) {
        //zmiana zmiennej alive aby usun¹æ pociski które wylec¹ z ekranu 
        if ((obiekt->getPosition().x > 1925) || (obiekt->getPosition().x < -5) || (obiekt->getPosition().y > 1925) || (obiekt->getPosition().y <-5)) {
            obiekt->alive = false;
        }
    }
    for (auto it = assets.begin(); it != assets.end(); ) {
        //usuwanie assetów z zmienn¹ alive=false
        if (!(*it)->alive) {
            it = assets.erase(it);
        }
        else {
            ++it;
        }
    }
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        //usuwanie pocisków z zmienn¹ alive=false
        if (!(*it)->alive) {
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }
    //wywo³anie metody do zmiany kolizji
    checkCollisions();
}

void Game::render()
{

    framecounter++;//licznik klatek
    window.clear();
    //wyœwietlanie obiektów na ekran
    background.draw(window);
    champion.draw(window);
    weapon.draw(window);
    for (auto& obiekt : assets)
    {
        obiekt->draw(window);

    }
    for (auto& obiekt : bullets)
    {
        obiekt->draw(window);

    }
    window.display();

}

void Game::spawnAsset()
{
    // Wygeneruj losow¹ pozycjê x na górze ekranu
    float xPos = static_cast<float>(10+rand() % window.getSize().x-20);

    // Wygeneruj losow¹ prêdkoœæ x i y
    float xVelocity = static_cast<float>(rand() % 201 - 100);
    float yVelocity = static_cast<float>(rand() % 200 + 100);
    int assetType = rand() % 11;
    AnimowaneAssety* newAsset = nullptr;//pusty wskaŸnik
    //moved to dodatkowy warunek dziêki któremu obiekty zaczn¹ sie pojawiaæ dopiero po poruszeniu gracz w prawo lub lewo
    //tworzenie obiektów w zale¿noœci od wylosowanej liczby, bomba 0-7 moneta-8,tarcza-9 i apteczka-10 
    if (assetType < 8&&moved==true) {
        newAsset = new Bomb(xPos, 0, xVelocity,yVelocity);
        std::cout << "utworzono bombe" << std::endl;
    }
    else if(moved==true){
        switch (assetType)
        {
        case 8:
            newAsset = new Coin(xPos, 0,0, yVelocity);
            std::cout << "utworzono monete" << std::endl;
            break;
        case 9:
            newAsset = new Shield(xPos, 0,0, yVelocity);
            std::cout << "utworzono tarcze" << std::endl;
            break;
        case 10:
            newAsset = new Aid(xPos, 0,0, yVelocity);
            std::cout << "utworzono apteczke" << std::endl;
            break;
        default:
            break;
        }
    }
    if (newAsset != nullptr)//jeœli uda³o sie przypisaæ do wskaŸnika 
    {
        // Dodaj do wektora
        assets.push_back(newAsset);
    }
}