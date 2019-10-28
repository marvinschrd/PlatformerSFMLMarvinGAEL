#pragma once
#include "SFML/Graphics.hpp"
#include "globals.h"

class Background
{
public:
	Background();
	void DrawBackground(sf::RenderWindow& window);
	void DrawHeart(sf::RenderWindow& window);
private:
	sf::Texture backGroundTexture_;
	sf::Sprite backGroundSprite_;
	sf::Texture heartTexture_;
	sf::Sprite heartSprite_;
	sf::Texture back_;
	
};
