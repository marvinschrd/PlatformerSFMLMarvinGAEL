#define _USE_MATH_DEFINES
#include "Platform.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "globals.h"
#include <iostream>
#include <math.h>

Platform::Platform() 
{
	gameObjectType_ = GameObjectType::PLATFORM;
	/*if (!platformTexture_.loadFromFile("data/Grass.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite_.setTexture(platformTexture_);*/

	
}

void Platform::Init(b2World& world)
{
	//platform1

	/*if (!platformTexture_.loadFromFile("data/platformFull1.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite_.setTexture(platformTexture_);

	platformSprite_.setPosition(20, 200);*/
	
	/*for (int i = 0; i < 4; i++)
	{
		platformsSprite1.push_back(platformSprite_);
	}*/

	/*for (int i = 0; i < platformsSprite1.size(); i++) {
		platformsSprite1[i].setPosition(20.0f + (i * 40.0f), 200.0f);
	}*/
	b2BodyDef bodyDef1;
	bodyDef1.type = b2_staticBody;
	bodyDef1.position = pixel2meter(platform1);
	platformBody1_ = world.CreateBody(&bodyDef1);
	b2PolygonShape shape1;
	shape1.SetAsBox(pixel2meter(boxSize1.x / 2.0f), pixel2meter(boxSize1.y / 2.0f));

	boxPlatform1RectDebug_.setSize(boxSize1);
	boxPlatform1RectDebug_.setOrigin(boxSize1 / 2.0f);
	boxPlatform1RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxPlatform1RectDebug_.setOutlineColor(sf::Color::Green);
	boxPlatform1RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef1;
	fixtureDef1.shape = &shape1;
	fixtureDef1.friction = 0.0f;
	fixtureDef1.density = 1;
	fixtureDef1.userData = this;
	platformBody1_->CreateFixture(&fixtureDef1);
	
	//platform2
	b2BodyDef bodyDef2;
	bodyDef2.type = b2_kinematicBody;
	bodyDef2.position = pixel2meter(platform2);
	platformBody2_ = world.CreateBody(&bodyDef2);
	
	b2PolygonShape shape2;
	shape2.SetAsBox(pixel2meter(boxSize2.x / 2.0f), pixel2meter(boxSize2.y / 2.0f));

	boxPlatform2RectDebug_.setSize(boxSize2);
	boxPlatform2RectDebug_.setOrigin(boxSize2 / 2.0f);
	boxPlatform2RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxPlatform2RectDebug_.setOutlineColor(sf::Color::Red);
	boxPlatform2RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef2;
	fixtureDef2.shape = &shape2;
	fixtureDef2.friction = 5.0f;
	fixtureDef2.density = 1;
	fixtureDef2.userData = this;
	platformBody2_->CreateFixture(&fixtureDef2);
	
	//platform3
	b2BodyDef bodyDef3;
	bodyDef3.type = b2_staticBody;
	bodyDef3.position = pixel2meter(platform3);
	platformBody3_ = world.CreateBody(&bodyDef3);
	b2PolygonShape shape3;
	shape3.SetAsBox(pixel2meter(boxSize3.x / 2.0f), pixel2meter(boxSize3.y / 2.0f));

	boxPlatform3RectDebug_.setSize(boxSize3);
	boxPlatform3RectDebug_.setOrigin(boxSize3 / 2.0f);
	boxPlatform3RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxPlatform3RectDebug_.setOutlineColor(sf::Color::Blue);
	boxPlatform3RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef3;
	fixtureDef3.shape = &shape3;
	fixtureDef3.friction = 1.0f;
	fixtureDef3.density = 1;
	fixtureDef3.userData = this;
	platformBody3_->CreateFixture(&fixtureDef3);
	
	//platform4

	b2BodyDef bodyDef4;
	bodyDef4.type = b2_kinematicBody;
	bodyDef4.position = pixel2meter(platform4);
	platformBody4_ = world.CreateBody(&bodyDef4);
	b2PolygonShape shape4;
	shape4.SetAsBox(pixel2meter(boxSize4.x / 2.0f), pixel2meter(boxSize4.y / 2.0f));

	boxPlatform4RectDebug_.setSize(boxSize4);
	boxPlatform4RectDebug_.setOrigin(boxSize4 / 2.0f);
	boxPlatform4RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxPlatform4RectDebug_.setOutlineColor(sf::Color::Black);
	boxPlatform4RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef4;
	fixtureDef4.shape = &shape4;
	fixtureDef4.friction = 1.0f;
	fixtureDef4.density = 1;
	fixtureDef4.userData = this;
	platformBody4_->CreateFixture(&fixtureDef4);

	//platform5
	b2BodyDef bodyDef5;
	bodyDef5.type = b2_kinematicBody;
	bodyDef5.position = pixel2meter(platform5);
	platformBody5_ = world.CreateBody(&bodyDef5);
	b2PolygonShape shape5;
	shape5.SetAsBox(pixel2meter(boxSize5.x / 2.0f), pixel2meter(boxSize5.y / 2.0f));

	boxPlatform5RectDebug_.setSize(boxSize5);
	boxPlatform5RectDebug_.setOrigin(boxSize5 / 2.0f);
	boxPlatform5RectDebug_.setFillColor(sf::Color(0, 255, 0, 120));
	boxPlatform5RectDebug_.setOutlineColor(sf::Color::White);
	boxPlatform5RectDebug_.setOutlineThickness(2.0f);

	b2FixtureDef fixtureDef5;
	fixtureDef5.shape = &shape5;
	fixtureDef5.friction = 1.0f;
	fixtureDef5.density = 0.0f;
	fixtureDef5.userData = this;
	platformBody5_->CreateFixture(&fixtureDef5);
}

void Platform::update()
{
	//platformBody2_->SetLinearVelocity(b2Vec2(-1,0));
	if (platformBody2_->GetPosition().x<=4.75 )
	{
		platformBody2_->SetLinearVelocity(b2Vec2(1, 0));
	}
	if (platformBody2_->GetPosition().x >= 6)
	{
		platformBody2_->SetLinearVelocity(b2Vec2(-1, 0));
	}
	//platformSprite2_.setRotation(platformBody2_->GetAngle()*(180/M_PI));

	if (platformBody4_->GetPosition().y <= pixel2meter(100))
	{
		platformBody4_->SetLinearVelocity(b2Vec2(0, 1));
	}
	if (platformBody4_->GetPosition().y >= pixel2meter(450))
	{
		platformBody4_->SetLinearVelocity(b2Vec2(0, -1));
	}

	platformBody5_->SetAngularVelocity(-1.5);
	platformSprite5_.setRotation(platformBody5_->GetAngle()*(180/M_PI));
}

void Platform::DrawPlatform(sf::RenderWindow& window)
{
	//platform1
	if (!platformTexture1_.loadFromFile("data/platformFull1.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite1_.setTexture(platformTexture1_);

	const auto platform1Size = sf::Vector2f(platformSprite1_.getLocalBounds().width, platformSprite1_.getLocalBounds().height);
	platformSprite1_.setOrigin(platform1Size / 2.0f);//lier l'origine du sprite avec l'objet

	platform1 = meter2pixel(platformBody1_->GetPosition());

	platformSprite1_.setPosition(platform1);
	
	window.draw(platformSprite1_);

	
	//platform2
	if (!platformTexture2_.loadFromFile("data/platformFull1.png"))
	{
		std::cerr << "[Error] Could not load texture\n";
	}
	platformSprite2_.setTexture(platformTexture2_);

	const auto platform2Size = sf::Vector2f(platformSprite2_.getLocalBounds().width, platformSprite2_.getLocalBounds().height);
	platformSprite2_.setOrigin(platform2Size / 2.0f);//lier l'origine du sprite avec l'objet
	
	platform2 = meter2pixel(platformBody2_->GetPosition());
	platformSprite2_.setPosition(platform2);

	window.draw(platformSprite2_);
	
	//platform3
	if (!platformTextureBig_.loadFromFile("data/big.png"))
	{
		std::cerr << "[Error] Could not load texture\n";
	}
	platformSpriteBig_.setTexture(platformTextureBig_);

	const auto platform3Size = sf::Vector2f(platformSpriteBig_.getLocalBounds().width, platformSpriteBig_.getLocalBounds().height);
	platformSpriteBig_.setOrigin(platform3Size / 2.0f);//lier l'origine du sprite avec l'objet

	platform3 = meter2pixel(platformBody3_->GetPosition());

	platformSpriteBig_.setPosition(platform3);

	window.draw(platformSpriteBig_);
	
	
	

	if (!grassTexture_.loadFromFile("data/grassRock.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	grassSprite_.setTexture(grassTexture_);
	grassSprite_.setPosition(210, 470);
	window.draw(grassSprite_);
	
	
	//platform4
	if (!platformTexture4_.loadFromFile("data/platformFull1.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite4_.setTexture(platformTexture4_);

	const auto platform4Size = sf::Vector2f(platformSprite4_.getLocalBounds().width, platformSprite4_.getLocalBounds().height);
	platformSprite4_.setOrigin(platform4Size / 2.0f);//lier l'origine du sprite avec l'objet

	platform4 = meter2pixel(platformBody4_->GetPosition());

	platformSprite4_.setPosition(platform4);

	window.draw(platformSprite4_);

	//platform5
	if (!platformTexture5_.loadFromFile("data/wood.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformSprite5_.setTexture(platformTexture5_);

	const auto platform5Size = sf::Vector2f(platformSprite5_.getLocalBounds().width, platformSprite5_.getLocalBounds().height);
	platformSprite5_.setOrigin(platform5Size / 2.0f);//lier l'origine du sprite avec l'objet

	platform5 = meter2pixel(platformBody5_->GetPosition());

	platformSprite5_.setPosition(platform5);

	window.draw(platformSprite5_);
	if (!platformCircleTexture.loadFromFile("data/circle.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	platformCircleSprite_.setTexture(platformCircleTexture);
	platformCircleSprite_.setPosition(487, 137);
	window.draw(platformCircleSprite_);
	

	boxPlatform2RectDebug_.setPosition(meter2pixel(platformBody2_->GetPosition()));
	boxPlatform1RectDebug_.setPosition(meter2pixel(platformBody1_->GetPosition()));
	boxPlatform3RectDebug_.setPosition(meter2pixel(platformBody3_->GetPosition()));
	boxPlatform4RectDebug_.setPosition(meter2pixel(platformBody4_->GetPosition()));
	boxPlatform5RectDebug_.setPosition(meter2pixel(platformBody5_->GetPosition()));
	/*window.draw(boxPlatform3RectDebug_);
	window.draw(boxPlatform1RectDebug_);
	window.draw(boxPlatform2RectDebug_);
	window.draw(boxPlatform4RectDebug_);*/
	//window.draw(boxPlatform5RectDebug_);
	
}



