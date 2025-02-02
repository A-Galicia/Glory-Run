#include <iostream>
#include <math.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include "Map.h";

int main()
{

    // --------------Initailze-----------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Glory Run", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);

    Player player;
    Enemy enemy;
    Map map;
    sf::Clock clock;
    FrameRate frameRate;
    MapLoader mapLoader;

    mapLoader.Load("assets/maps/level 1.txt");


    player.Initilize();
    enemy.Initilize();
    map.Initilize();


    // --------------Initailze-----------------------


    //---------------Load----------------------------

    enemy.Load();
    player.Load();
    map.Load();

    //---------------Load----------------------------

    // main game loop-------------------------------------------------------------------------------------------------------------------
	while (window.isOpen()) {

        //---------------update--------------------------

        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMilliseconds(); 


        while (const std::optional event = window.pollEvent())
        {
            // Window closed or escape key pressed: exit
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                    event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();

        }

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        map.Update();
        enemy.Update(deltaTime);
        player.Update(deltaTime, enemy, mousePosition);
        frameRate.Update(deltaTime);

        //---------------update--------------------------

        //---------------draw----------------------------

        window.clear(sf::Color::Red);
        map.Draw(window);
        enemy.Draw(window);
        player.Draw(window);
        frameRate.Draw(window);
        window.display();
        //---------------draw----------------------------

        
	}

	return 0;
}