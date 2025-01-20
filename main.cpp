#include <iostream>
#include <math.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"



int main()
{

    // --------------Initailze-----------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Glory Run", sf::Style::Default, sf::State::Windowed, settings);

    Player player;
    Enemy enemy;

    player.Initilize();
    enemy.Initilize();

    // --------------Initailze-----------------------



    //---------------Load----------------------------
    
    enemy.Load();
    player.Load();

    //---------------Load----------------------------

    // main game loop-------------------------------------------------------------------------------------------------------------------
	while (window.isOpen()) {

        //---------------update--------------------------

        while (const std::optional event = window.pollEvent())
        {
            // Window closed or escape key pressed: exit
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                    event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();

        }

        player.Update(enemy);

        //---------------update--------------------------

        //---------------draw----------------------------

        window.clear(sf::Color::Black);
        enemy.Draw(window);
        player.Draw(window);
  
        window.display();
        //---------------draw----------------------------
	}

	return 0;
}