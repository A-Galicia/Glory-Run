#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :
    health(100){

}

void Enemy::SetHealth(int hp) {
    health += hp;
    healthText.setString(std::to_string(health));
}

void Enemy::Initilize() {
    boundingRect.setFillColor(sf::Color::Transparent);
    boundingRect.setOutlineColor(sf::Color::Blue);
    boundingRect.setOutlineThickness(1);
    boundingRect.setSize(sf::Vector2f(64, 64));
}

void Enemy::Load() {

    if (!font.openFromFile("assets/arial.ttf")) {
        std::cout << "Couldn't open Font file\n";
    }
    else {
        std::cout << "Loaded font: Arial\n";
        healthText.setFont(font);
        
    }

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

    
}

void Enemy::Update(double deltaTime) {
    if (health > 0) {
        boundingRect.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());
        healthText.setString(std::to_string(health));
    }

}

void Enemy::Draw(sf::RenderWindow& window) {
    if (health > 0) {
        window.draw(sprite);
        window.draw(boundingRect);
        window.draw(healthText);

    }
}