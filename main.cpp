#include <iostream>
#include <math.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Player.h"

sf::Vector2f normalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVec;
    normalizedVec.x = vector.x / m;
    normalizedVec.y = vector.y / m;

    return normalizedVec;
}

int main()
{

    // --------------Initailze-----------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Glory Run", sf::Style::Default, sf::State::Windowed, settings);

    player.Initialize();
    player.Load();
    // --------------Initailze-----------------------

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 5.0f;

    //---------------Load----------------------------
    

    sf::Texture enemyTexture("assets/enemy/textures/BODY_skeleton.png");
    sf::Sprite enemySprite(enemyTexture);
    if (enemyTexture.loadFromFile("assets/player/textures/BODY_skeleton.png")) {
        std::cout << "Enemy image loaded\n";
        enemySprite.setPosition({100, 700});
        int xIndex = 0;
        int yIndex = 0;

        enemySprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        enemySprite.scale(sf::Vector2f(1, 1));
    }
    else {
        std::cout << "Enemy image failed to load\n";
    }



    
    




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




        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::RectangleShape newBullet(sf::Vector2f(10.0f, 5.0f));
            bullets.push_back(newBullet);
            int i = bullets.size() - 1;
            bullets[i].setPosition(player.sprite.getPosition());


        }

        for (int i = 0; i < bullets.size(); i++) {
            sf::Vector2f bulletdirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletdirection = normalizeVector(bulletdirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletdirection * bulletSpeed);
        }

        player.Update();

        //---------------update--------------------------

        //---------------draw----------------------------

        window.clear(sf::Color::Black);
        window.draw(enemySprite);
        window.draw(player.sprite);

        for (int i = 0; i < bullets.size(); i++)
            window.draw(bullets[i]);

        window.display();

        //---------------draw----------------------------








	}

	return 0;
}