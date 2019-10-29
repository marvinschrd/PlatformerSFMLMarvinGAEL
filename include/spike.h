#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

class Spike : public GameObject
{
public:
	Spike();
	void DrawSpikeBlock(sf::RenderWindow& window, bool setSpikeBlock);
	void init(b2World& world);
private:
	sf::Texture spikeBlockTexture_;
	sf::Sprite spikeBlockSprite_;
	b2Body* spikeBlockBody_ = nullptr;
	sf::Vector2f spikeBlockPosition_ = sf::Vector2f(350, -45);
	const sf::Vector2f boxSize = sf::Vector2f(100, 100);
	sf::RectangleShape boxSpikeBlockRectDebug_;
};
