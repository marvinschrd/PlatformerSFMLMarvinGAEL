#include "WinObject.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>

WinObject::WinObject()
{
	gameObjectType_ = GameObjectType::WINOBJECT;



}

void WinObject::Init(b2World& world)
{
	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody;
	bodyDef1.position = pixel2meter(winObject);
	winObjectBody1_ = world.CreateBody(&bodyDef1);
	b2PolygonShape shape1;
	shape1.SetAsBox(pixel2meter(boxSize1.x / 2.0f), pixel2meter(boxSize1.y / 2.0f));

	boxWinObjectRectDebug_.setSize(boxSize1);
	boxWinObjectRectDebug_.setOrigin(boxSize1 / 2.0f);
	boxWinObjectRectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxWinObjectRectDebug_.setOutlineColor(sf::Color::Blue);
	boxWinObjectRectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef1;
	fixtureDef1.shape = &shape1;
	fixtureDef1.friction = 0.0f;
	fixtureDef1.density = 1;
	fixtureDef1.userData = this;
	winObjectBody1_->CreateFixture(&fixtureDef1);


}
void WinObject::DrawWinObject(sf::RenderWindow& window)
{
	if (!winObjectTexture_.loadFromFile("data/apple.png"))
	{
		std::cerr << "[Error] Could not load Win texture\n";
	}
	winObjectSprite_.setTexture(winObjectTexture_);

	winObjectSprite_.setPosition(670, 220);
	window.draw(winObjectSprite_);


	/*boxWinObjectRectDebug_.setPosition(meter2pixel(winObjectBody1_->GetPosition()));
	window.draw(boxWinObjectRectDebug_);*/


}