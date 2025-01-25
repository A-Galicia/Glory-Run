#include "Math.h"
#include <iostream>

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector) {
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVec;
    normalizedVec.x = vector.x / m;
    normalizedVec.y = vector.y / m;

    return normalizedVec;
}

bool Math::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2) {
    if (rect1.contains(rect2.position) ||
        rect1.contains(rect2.position + sf::Vector2f(64, 0)) ||
        rect1.contains(rect2.position + sf::Vector2f(0, 64)) ||
        rect1.contains(rect2.position + sf::Vector2f(64, 64))) {

        return true;
    }

        return false;
}

FrameRate::FrameRate() {
    if (!font.openFromFile("assets/arial.ttf")) {
        std::cout << "Couldn't open Font file\n";
    }
    else {
        std::cout << "Loaded font: Arial\n";
        frameRateText.setFont(font);
    }
}

void FrameRate::Update(float deltaTime) {
    timer += deltaTime;
    
    if (timer > 100.0f) {
        frameRateText.setString("FPS: " + std::to_string(static_cast<int>(1000 / deltaTime)) +
                                " FrameTime: " + std::to_string(static_cast<int>(deltaTime)));
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow& window) {
    window.draw(frameRateText);
}