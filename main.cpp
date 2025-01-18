#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // --------------Initailze-----------------------
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Glory Run", sf::Style::Default, sf::State::Windowed, settings);

    sf::CircleShape shape(50.0f, 12);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Green);
    
    sf::RectangleShape rectangle(sf::Vector2f(200, 2));
    rectangle.setPosition(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color::Blue);
    //rectangle.setOrigin(sf::Vector2f(50.0f, 25.0f));
    rectangle.setRotation(sf::degrees(45));

    // --------------Initailze-----------------------


    //---------------Load----------------------------
    
    sf::Texture playerTexture("assets/player/textures/BODY_skeleton.png");
    sf::Sprite playerSprite(playerTexture);
    if (playerTexture.loadFromFile("assets/player/textures/BODY_skeleton.png")) {
        std::cout << "Player image loaded\n";
        playerSprite.setTexture(playerTexture);

        int xIndex = 4;
        int yIndex = 2;

        playerSprite.setTextureRect( sf::IntRect({xIndex*64, yIndex*64}, {64, 64}));
        playerSprite.scale(sf::Vector2f(3, 3));
    }
    else {
        std::cout << "Player image failed to load\n";
    }




    //---------------Load----------------------------



    // main game loop
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

        // Handle Player MOvement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            playerSprite.move({ 0, -1.0f });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            playerSprite.move({ 0, 1.0f });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            playerSprite.move({ -1.0f, 0 });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            playerSprite.move({ 1.0f, 0 });


        //---------------update--------------------------

        //---------------draw----------------------------

        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();

        //---------------draw----------------------------








	}

	return 0;
}