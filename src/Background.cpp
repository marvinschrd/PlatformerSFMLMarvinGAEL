#include "Background.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>


Background::Background()
{
	if (!backgroundTexture_.loadFromFile("data/back.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	backgroundSprite_.setTexture(backgroundTexture_);
}

void Background::DrawBackground(sf::RenderWindow& window)
{
	window.draw(backgroundSprite_);
}
