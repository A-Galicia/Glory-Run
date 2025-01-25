#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
private:
    sf::Texture texture = sf::Texture("assets/player/textures/BODY_skeleton.png");

    sf::RectangleShape boundingRect;

    std::vector<sf::RectangleShape> bullets;
    float bulletSpeed;
    float playerSpeed;
    float maxfireRate;
    float fireRateTimer;
public:
    sf::Sprite sprite = sf::Sprite(texture);
    Player();
    void Initilize();
    void Load();
    void Update(float deltaTime, Enemy &enemy);
    void Draw(sf::RenderWindow &window);
};