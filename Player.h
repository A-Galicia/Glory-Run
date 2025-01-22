#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
    sf::Texture texture = sf::Texture("assets/player/textures/BODY_skeleton.png");

    sf::RectangleShape boundingRect;

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed = 5.0f;
    float playerSpeed = 1.0f;
public:
    sf::Sprite sprite = sf::Sprite(texture);
    void Initilize();
    void Load();
    void Update(float deltaTime, Enemy &enemy);
    void Draw(sf::RenderWindow &window);
};