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


    // main game loop
	while (window.isOpen()) {

        while (const std::optional event = window.pollEvent())
        {
            // Window closed or escape key pressed: exit
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                    event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();

            
        }


        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.display();









	}

	return 0;
}