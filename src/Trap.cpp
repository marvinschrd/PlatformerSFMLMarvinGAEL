#include "Trap.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>

Trap::Trap()
{
	gameObjectType_ = GameObjectType::TRAP;



}

void Trap::Init(b2World& world)
{
	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody;
	bodyDef1.position = pixel2meter(trap1);
	trapBody1_ = world.CreateBody(&bodyDef1);
	b2PolygonShape shape1;
	shape1.SetAsBox(pixel2meter(boxSize1.x / 2.0f), pixel2meter(boxSize1.y / 2.0f));

	boxTrap1RectDebug_.setSize(boxSize1);
	boxTrap1RectDebug_.setOrigin(boxSize1 / 2.0f);
	boxTrap1RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxTrap1RectDebug_.setOutlineColor(sf::Color::Blue);
	boxTrap1RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef1;
	fixtureDef1.shape = &shape1;
	fixtureDef1.friction = 0.0f;
	fixtureDef1.density = 1;
	fixtureDef1.userData = this;
	trapBody1_->CreateFixture(&fixtureDef1);


}
void Trap::DrawTrap(sf::RenderWindow& window)
{	
	if (!trapTextureSpike_.loadFromFile("data/spike.png"))
	{
		std::cerr << "[Error] Could not load spike1 texture\n";
	}
	trapSpriteSpike_.setTexture(trapTextureSpike_);

	trapSpriteSpike_.setPosition(280, 365);
	window.draw(trapSpriteSpike_);

	if (!trapTextureSpike_.loadFromFile("data/spike.png"))
	{
		std::cerr << "[Error] Could not load spike2 texture\n";
	}
	trapSpriteSpike_.setTexture(trapTextureSpike_);

	trapSpriteSpike_.setPosition(295, 365);
	window.draw(trapSpriteSpike_);

	if (!trapTextureSpike_.loadFromFile("data/spike.png"))
	{
		std::cerr << "[Error] Could not load spike3 texture\n";
	}
	trapSpriteSpike_.setTexture(trapTextureSpike_);

	trapSpriteSpike_.setPosition(265, 365);
	window.draw(trapSpriteSpike_);


	/*boxTrap1RectDebug_.setPosition(meter2pixel(trapBody1_->GetPosition()));
	window.draw(boxTrap1RectDebug_);*/


}



