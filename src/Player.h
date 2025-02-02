#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Math.h"

class Player
{
private:
    sf::Texture texture = sf::Texture("assets/player/textures/BODY_skeleton.png");

    sf::RectangleShape boundingRect;
    std::vector<Bullet> bullets;
    float playerSpeed;
    float maxfireRate;
    double fireRateTimer;
public:
    sf::Sprite sprite = sf::Sprite(texture);
    Player();
    void Initilize();
    void Load();
    void Update(double deltaTime, Enemy &enemy, sf::Vector2f &mousePosition);
    void Draw(sf::RenderWindow &window);
};