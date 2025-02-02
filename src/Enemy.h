#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture texture = sf::Texture("assets/enemy/textures/BODY_skeleton.png");

    sf::Font font;
    sf::Text healthText = sf::Text(font);

    sf::RectangleShape boundingRect;
public:
    int health;
    sf::Sprite sprite = sf::Sprite(texture);
    Enemy();
    void SetHealth(int hp);
    void Initilize();
    void Load();
    void Update(double deltaTime);
    void Draw(sf::RenderWindow& window);
};