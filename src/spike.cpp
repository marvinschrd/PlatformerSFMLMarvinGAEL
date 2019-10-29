#include "spike.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"


Spike::Spike()
{
	gameObjectType_ = GameObjectType::SPIKE;
}

void Spike::init(b2World& world)
{
	if (!spikeBlockTexture_.loadFromFile("data/spikeBlock.png"))
	{
		std::cerr << "[Error] Could not load texture\n";
	}
	spikeBlockSprite_.setTexture(spikeBlockTexture_);

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = pixel2meter(spikeBlockPosition_);
	spikeBlockBody_ = world.CreateBody(&bodyDef);



	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(boxSize.x / 2.0f), pixel2meter(boxSize.y / 2.0f));

	boxSpikeBlockRectDebug_.setSize(boxSize);
	boxSpikeBlockRectDebug_.setOrigin(boxSize / 2.0f);
	boxSpikeBlockRectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxSpikeBlockRectDebug_.setOutlineColor(sf::Color::Green);
	boxSpikeBlockRectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 10000.0f;
	fixtureDef.density = 100000;
	fixtureDef.userData = this;
	spikeBlockBody_->CreateFixture(&fixtureDef);
}
void Spike::DrawSpikeBlock(sf::RenderWindow& window, bool setSpikeBlock)
{

	if (!spikeBlockTexture_.loadFromFile("data/spikeBlock.png"))
	{
		std::cerr << "[Error] Could not load texture\n";
	}
	spikeBlockSprite_.setTexture(spikeBlockTexture_);

	if (setSpikeBlock == true)
	{
		spikeBlockBody_->SetType(b2_dynamicBody);
	}

	const auto spikeBlockSize = sf::Vector2f(spikeBlockSprite_.getLocalBounds().width, spikeBlockSprite_.getLocalBounds().height);
	spikeBlockSprite_.setOrigin(spikeBlockSize / 2.0f);//lier l'origine du sprite avec l'objet

	spikeBlockPosition_ = meter2pixel(spikeBlockBody_->GetPosition());
	spikeBlockSprite_.setPosition(spikeBlockPosition_);

	window.draw(spikeBlockSprite_);

}

