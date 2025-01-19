#include "Player.h"
#include <iostream>

void Player::Initialize() {

}

void Player::Load() {
    if (texture.loadFromFile("assets/player/textures/BODY_skeleton.png")) {
        std::cout << "Player image loaded\n";
        sprite.setPosition({ 1650, 800 });
        int xIndex = 4;
        int yIndex = 2;

        sprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
        sprite.scale(sf::Vector2f(1, 1));
    }
    else {
        std::cout << "Player image failed to load\n";
    }
}

void Player::Update() {

    // Handle Player MOvement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.move({ 0, -1.0f });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.move({ 0, 1.0f });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.move({ -1.0f, 0 });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.move({ 1.0f, 0 });
}

void Player::Draw() {

}