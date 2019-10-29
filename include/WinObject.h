#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

class WinObject : public GameObject
{
public:
	WinObject();
	void DrawWinObject(sf::RenderWindow& window);
	void Init(b2World& world);
private:

	sf::Texture winObjectTexture_;
	sf::Sprite winObjectSprite_;
	std::vector<sf::Sprite> winObjectSprite;
	
	b2Body* winObjectBody1_ = nullptr;
	sf::Vector2f winObject = sf::Vector2f(687, 237);
	sf::RectangleShape boxWinObjectRectDebug_;
	const sf::Vector2f boxSize1 = sf::Vector2f(28, 28);

};