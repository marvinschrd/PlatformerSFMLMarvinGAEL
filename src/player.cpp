#include "player.h"
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include <iostream>
#include "globals.h"


player::player()// ouvre le fichier image qui represente le personnage
{
	if (!playerTexture_.loadFromFile("data/cat.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	playerSprite_.setTexture(playerTexture_);
	
}


void player::init(b2World& world)
{
	const auto playerSize = sf::Vector2f(playerSprite_.getLocalBounds().width, playerSprite_.getLocalBounds().height);
	playerSprite_.setOrigin(playerSize / 2.0f);
	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position = pixel2meter(playerPosition_);//
	//bodyDef.position.Set(50, 50);
	bodyDef.fixedRotation = true;//
	playerBody_ = world.CreateBody(&bodyDef);


	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(boxSize.x) / 2.0f, pixel2meter(boxSize.y) / 2.0f);
	boxRectDebug_.setSize(boxSize);
	boxRectDebug_.setOrigin(boxSize / 2.0f);
	boxRectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxRectDebug_.setOutlineColor(sf::Color::Green);
	boxRectDebug_.setOutlineThickness(2.0f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 0.0f;
	fixtureDef.density = 1;
	fixtureDef.userData = this;
	playerBody_->CreateFixture(&fixtureDef);
}

void player::DrawPlayer(sf::RenderWindow& window)
{
	playerPosition_ = meter2pixel(playerBody_->GetPosition());
	playerSprite_.setPosition(playerPosition_);
	boxRectDebug_.setPosition(meter2pixel(playerBody_->GetPosition()));
	window.draw(playerSprite_);
	window.draw(boxRectDebug_);
}

