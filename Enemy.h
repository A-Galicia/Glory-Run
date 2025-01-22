#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
private:
    sf::Texture texture = sf::Texture("assets/enemy/textures/BODY_skeleton.png");

    sf::RectangleShape boundingRect;
public:
    sf::Sprite sprite = sf::Sprite(texture);
    void Initilize();
    void Load();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
};