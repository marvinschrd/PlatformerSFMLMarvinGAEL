#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

class Platform : public GameObject
{
public:
	Platform();
	void DrawPlatform(sf::RenderWindow& window);
	void Init(b2World& world);
private:
	sf::Texture platformTexture_;
	sf::Sprite platformSprite_;
	std::vector<sf::Sprite> platformsSprite1;
	std::vector<sf::Sprite> platformsSprite2;
	
};
