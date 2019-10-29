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
	void update();
private:
	sf::Texture platformTexture1_;
	sf::Sprite platformSprite1_;
	sf::Texture platformTexture2_;
	sf::Sprite platformSprite2_;
	sf::Texture platformTextureBig_;
	sf::Sprite platformSpriteBig_;
	sf::Texture platformTexture4_;
	sf::Sprite platformSprite4_;
	sf::Texture platformTexture5_;
	sf::Sprite platformSprite5_;
	sf::Texture grassTexture_;
	sf::Sprite grassSprite_;
	sf::Texture platformCircleTexture;
	sf::Sprite platformCircleSprite_;
	
	/*std::vector<sf::Sprite> platformsSprite1;
	std::vector<sf::Sprite> platformsSprite2;
	std::vector<sf::Sprite> platformsSprite3;*/
	b2Body* platformBody1_ = nullptr;
	sf::Vector2f platform1 = sf::Vector2f(200, 150);
	b2Body* platformBody2_ = nullptr;
	sf::Vector2f platform2 = sf::Vector2f(680, 350);
	b2Body* platformBody3_ = nullptr;
	sf::Vector2f platform3 = sf::Vector2f(290, 515);
	b2Body* platformBody4_ = nullptr;
	sf::Vector2f platform4 = sf::Vector2f(800, 515);
	b2Body* platformBody5_ = nullptr;
	sf::Vector2f platform5 = sf::Vector2f(500,150);
	
	sf::RectangleShape boxPlatform1RectDebug_;
	sf::RectangleShape boxPlatform2RectDebug_;
	sf::RectangleShape boxPlatform3RectDebug_;
	sf::RectangleShape boxPlatform4RectDebug_;
	sf::RectangleShape boxPlatform5RectDebug_;
	const sf::Vector2f boxSize1 = sf::Vector2f(150, 30);
	const sf::Vector2f boxSize2 = sf::Vector2f(150, 30);
	const sf::Vector2f boxSize3 = sf::Vector2f(270, 30);
	const sf::Vector2f boxSize4 = sf::Vector2f(150, 30);
	const sf::Vector2f boxSize5 = sf::Vector2f(200, 30);
	
};
