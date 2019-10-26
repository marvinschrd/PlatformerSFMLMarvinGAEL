#include "player.h"
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include <iostream>


player::player()// ouvre le fichier image qui represente le personnage
{
	if (!playerTexture_.loadFromFile("data/cat.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	playerSprite_.setTexture(playerTexture_);
	
}

void player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(playerSprite_);
}


