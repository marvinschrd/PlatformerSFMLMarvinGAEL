#include "Background.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>


Background::Background()
{
	if (!backGroundTexture_.loadFromFile("data/back.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	backGroundSprite_.setTexture(backGroundTexture_);
}

void Background::DrawBackground(sf::RenderWindow& window)
{
	window.draw(backGroundSprite_);
}

void Background::DrawHeart(sf::RenderWindow& window)
{
	if (!heartTexture_.loadFromFile("data/heart.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	heartSprite_.setTexture(heartTexture_);

	heartSprite_.setPosition(10.0f, 10);
	window.draw(heartSprite_);
	heartSprite_.setPosition(45, 10);
	window.draw(heartSprite_);
}
