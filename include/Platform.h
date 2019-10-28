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
	sf::Texture platformTextureBig_;
	sf::Sprite platformSpriteBig_;
	std::vector<sf::Sprite> platformsSprite1;
	std::vector<sf::Sprite> platformsSprite2;
	std::vector<sf::Sprite> platformsSprite3;
	b2Body* platformBody1_ = nullptr;
	sf::Vector2f platform1 = sf::Vector2f(100, 225);
	b2Body* platformBody2_ = nullptr;
	sf::Vector2f platform2 = sf::Vector2f(680, 275);
	b2Body* platformBody3_ = nullptr;
	sf::Vector2f platform3 = sf::Vector2f(290, 425);
	sf::RectangleShape boxPlatform1RectDebug_;
	sf::RectangleShape boxPlatform2RectDebug_;
	sf::RectangleShape boxPlatform3RectDebug_;
	const sf::Vector2f boxSize1 = sf::Vector2f(150, 30);
	const sf::Vector2f boxSize2 = sf::Vector2f(150, 30);
	const sf::Vector2f boxSize3 = sf::Vector2f(270, 30);
	
};
