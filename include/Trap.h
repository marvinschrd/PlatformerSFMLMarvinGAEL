#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

class Trap : public GameObject
{
public:
	Trap();
	void DrawTrap(sf::RenderWindow& window);
	void Init(b2World& world);
private:

	sf::Texture trapTextureSpike_;
	sf::Sprite trapSpriteSpike_;
	std::vector<sf::Sprite> trapSprite1;
	b2Body* trapBody1_ = nullptr;
	sf::Vector2f trap1 = sf::Vector2f(295, 390);
	sf::RectangleShape boxTrap1RectDebug_;
	const sf::Vector2f boxSize1 = sf::Vector2f(55, 20);

};
