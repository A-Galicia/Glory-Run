#include "Player.h"
#include "Math.h"
#include <iostream>

Player::Player() : 
    bulletSpeed(.5), playerSpeed(1), maxfireRate(250), fireRateTimer(0) {

}

void Player::Initilize() {
    boundingRect.setFillColor(sf::Color::Transparent);
    boundingRect.setOutlineColor(sf::Color::Red);
    boundingRect.setOutlineThickness(1);
    boundingRect.setSize(sf::Vector2f(64, 64));
}

void Player::Load() {
    if (texture.loadFromFile("assets/player/textures/BODY_skeleton.png")) {
        std::cout << "Enemy image loaded\n";
        sprite.setPosition({ 960, 540 });
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
void Player::Update(float deltaTime, Enemy &enemy) {
    // Handle Movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        sprite.move({ 0, -1.0f * playerSpeed * deltaTime });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        sprite.move({ 0, 1.0f * playerSpeed * deltaTime });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        sprite.move({ -1.0f * playerSpeed * deltaTime, 0 });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        sprite.move({ 1.0f * playerSpeed * deltaTime, 0 });

    boundingRect.setPosition(sprite.getPosition());


    // Handle bullets
    fireRateTimer += deltaTime;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxfireRate) {
        sf::RectangleShape newBullet(sf::Vector2f(10.0f, 5.0f));
        bullets.push_back(newBullet);
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());

        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++) {
        sf::Vector2f bulletdirection = enemy.sprite.getPosition() - bullets[i].getPosition();
        bulletdirection = Math::NormalizeVector(bulletdirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletdirection * bulletSpeed * deltaTime);

        if (Math::CheckRectCollision(bullets[i].getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
            bullets.erase(bullets.begin() + i);
            std::cout << "Collision!";
        }
    }

}

void Player::Draw(sf::RenderWindow &window) {
    window.draw(sprite);
    window.draw(boundingRect);

    for (int i = 0; i < bullets.size(); i++)
        window.draw(bullets[i]);

}
