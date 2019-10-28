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

void Background::DrawHeart(sf::RenderWindow& window, int playerHealth)
{
	if (!heartTexture_.loadFromFile("data/heart.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	heartSprite_.setTexture(heartTexture_);

	if (playerHealth >= 1&&  playerHealth <=3)
	{
		heartSprite_.setPosition(10.0f, 10);
		window.draw(heartSprite_);
	}
	if (playerHealth >= 2 && playerHealth <= 3)
	{
		heartSprite_.setPosition(45, 10);
		window.draw(heartSprite_);
	}
	if(playerHealth ==3)
	{

		heartSprite_.setPosition(80, 10);
		window.draw(heartSprite_);
	}
}
