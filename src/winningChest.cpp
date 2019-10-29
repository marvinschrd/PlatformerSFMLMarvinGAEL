#include "winningChest.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"

winningChest::winningChest()
{
	gameObjectType_ = GameObjectType::CHEST;

}


void winningChest::init(b2World& world)
{
	if (!chestTexture_.loadFromFile("data/Chest.png"))
	{
		std::cerr << "[Error] Could not load texture\n";
	}
	chestSprite_.setTexture(chestTexture_);

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = pixel2meter(chestPosition_);
	chestBody_ = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(boxSize.x / 2.0f), pixel2meter(boxSize.y / 2.0f));

	boxChestkRectDebug_.setSize(boxSize);
	boxChestkRectDebug_.setOrigin(boxSize / 2.0f);
	boxChestkRectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxChestkRectDebug_.setOutlineColor(sf::Color::Green);
	boxChestkRectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 10000.0f;
	fixtureDef.density = 100000;
	fixtureDef.userData = this;
	chestBody_->CreateFixture(&fixtureDef);
}

void winningChest::drawChest(sf::RenderWindow& window)
{
	const auto spikeBlockSize = sf::Vector2f(chestSprite_.getLocalBounds().width, chestSprite_.getLocalBounds().height);
	chestSprite_.setOrigin(spikeBlockSize / 2.0f);//lier l'origine du sprite avec l'objet

	chestPosition_ = meter2pixel(chestBody_->GetPosition());
	chestSprite_.setPosition(chestPosition_);

	window.draw(chestSprite_);
}