#pragma once
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "globals.h"

class player
{
public:
	player();
	void DrawPlayer(sf::RenderWindow& window);
	void init(b2World& world);
private:
	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
	sf::RectangleShape boxRectDebug_;
	sf::Vector2f playerPosition_ = sf::Vector2f(100, 100);
	b2Body* playerBody_ = nullptr;
	const sf::Vector2f boxSize = sf::Vector2f(40, 70);
};
