#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

class winningChest : public GameObject
{
public:
	winningChest();
	void drawChest(sf::RenderWindow& window);
	void init(b2World& world);

private:
	sf::Texture chestTexture_;
	sf::Sprite chestSprite_;
	b2Body* chestBody_ = nullptr;
	sf::Vector2f chestPosition_ = sf::Vector2f(170, 120);
	const sf::Vector2f boxSize = sf::Vector2f(35, 35);
	sf::RectangleShape boxChestkRectDebug_;
};
