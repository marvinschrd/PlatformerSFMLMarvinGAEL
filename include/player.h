#pragma once
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "globals.h"

class player : public GameObject
{
public:
	player();
	void DrawPlayer(sf::RenderWindow& window);
	void init(b2World& world);
	void Update(float dt);

	void OnContactBegin();
	void OnContactEnd();
	void OnSpikeContact();
	int playerHealth_ = 3;
	bool setSpikeBlock = false;
	bool chestContact_ = false;
private:
	bool spikeContact = false;
	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
	sf::RectangleShape boxRectDebug_;
	sf::Vector2f playerPosition_ = sf::Vector2f(200, 300);
	b2Body* playerBody_ = nullptr;
	const sf::Vector2f boxSize = sf::Vector2f(40, 70);
	
	const pixel playerSpeed_ = 200.0f;//in pixels
	const float movementFactor_ = 0.7f;
	const meter jumpVelocity_ = -6.05f;//in meter
	bool previousJumpButton_ = false;
	int contactNmb_ = 0;
};
