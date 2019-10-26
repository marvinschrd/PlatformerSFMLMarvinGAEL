#pragma once
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "globals.h"

class player
{
public:
	player();
	void DrawPlayer(sf::RenderWindow& window);
	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
};
