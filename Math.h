#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static bool CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2);
};

class FrameRate {
	sf::Font font;
	sf::Text frameRateText = sf::Text(font);
	float timer = 0;
public:
	FrameRate();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};