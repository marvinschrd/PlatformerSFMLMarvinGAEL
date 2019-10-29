#include "player.h"
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include <iostream>
#include "globals.h"


player::player()// ouvre le fichier image qui represente le personnage
{
	if (!playerTexture_.loadFromFile("data/idle.png"))
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

//PAS FAIT PAR MOI

void player::Update(float dt)
{
	float jump = playerBody_->GetLinearVelocity().y;
	bool jumpButton = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	if (jumpButton && !previousJumpButton_ && contactNmb_ > 0)
	{
		
		jump = jumpVelocity_;
	}

	if (!playerTexture_.loadFromFile("data/idle.png"))
	{
		std::cerr << "[Error] Could not load hero texture\n";
	}
	playerSprite_.setTexture(playerTexture_);
	
	float move = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!playerTexture_.loadFromFile("data/idle2.png"))
		{
			std::cerr << "[Error] Could not load hero texture\n";
		}
		playerSprite_.setTexture(playerTexture_);
		move -= 1.0f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!playerTexture_.loadFromFile("data/idle.png"))
		{
			std::cerr << "[Error] Could not load hero texture\n";
		}
		playerSprite_.setTexture(playerTexture_);
		move += 1.0f;
		
	}

	const float deltaVx = move * pixel2meter(playerSpeed_) - playerBody_->GetLinearVelocity().x;
	const float fx = movementFactor_ * playerBody_->GetMass() * deltaVx / dt;

	const float deltaVy = jump - playerBody_->GetLinearVelocity().y;
	const float fy = playerBody_->GetMass() * deltaVy / dt;
	playerBody_->ApplyForce(b2Vec2(fx, fy), playerBody_->GetWorldCenter(), true);

	previousJumpButton_ = jumpButton;
}


void player::DrawPlayer(sf::RenderWindow& window)
{
	playerPosition_ = meter2pixel(playerBody_->GetPosition());
	playerSprite_.setPosition(playerPosition_);
	boxRectDebug_.setPosition(meter2pixel(playerBody_->GetPosition()));
	window.draw(playerSprite_);
	//window.draw(boxRectDebug_);
}

void player::OnContactBegin()
{
	contactNmb_++;
}
void player::OnContactEnd()
{
	contactNmb_--;
}

void player::Win()
{
	contactWin_++;
}
