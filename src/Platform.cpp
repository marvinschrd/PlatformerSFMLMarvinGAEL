#include "Platform.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>

Platform::Platform() 
{
	gameObjectType_ = GameObjectType::PLATFORM;
	if (!platformTexture_.loadFromFile("data/Grass.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite_.setTexture(platformTexture_);

	
}

void Platform::Init(b2World& world)
{
	//platform1
	for (int i = 0; i < 7; i++)
	{
		platformsSprite1.push_back(platformSprite_);
	}
	for (int i = 0; i < platformsSprite1.size(); i++) {
		platformsSprite1[i].setPosition(20.0f + (i * 40.0f), 200.0f);
	}
	//platform2
	for (int i = 0; i < 4; i++)
	{
		platformsSprite2.push_back(platformSprite_);
	}
	for (int i = 0; i < platformsSprite2.size(); i++) {
		platformsSprite2[i].setPosition(40.0f + (i * 40.0f), 250.0f);
	}
	
	
	
}
void Platform::DrawPlatform(sf::RenderWindow& window)
{

	for (int i = 0; i < platformsSprite1.size(); i++)
	{
		window.draw(platformsSprite1[i]);
	}

	for (int i = 0; i < platformsSprite2.size(); i++)
	{
		window.draw(platformsSprite2[i]);
	}
	
	
	
}



