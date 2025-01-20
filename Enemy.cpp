#include "Enemy.h"
#include <iostream>

void Enemy::Initilize() {
    boundingRect.setFillColor(sf::Color::Transparent);
    boundingRect.setOutlineColor(sf::Color::Blue);
    boundingRect.setOutlineThickness(1);
    boundingRect.setSize(sf::Vector2f(64, 64));
}

void Enemy::Load() {
    if (texture.loadFromFile("assets/player/textures/BODY_skeleton.png")) {
        std::cout << "Enemy image loaded\n";
        sprite.setPosition({ 100, 100 });
        int xIndex = 0;
        int yIndex = 0;

        //sprite.setOrigin(sf::Vector2f(32, 32));
        sprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        sprite.scale(sf::Vector2f(1, 1));
    }
    else {
        std::cout << "Enemy image failed to load\n";
    }

    boundingRect.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    window.draw(boundingRect);
}