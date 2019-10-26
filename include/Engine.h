#pragma once
#include "player.h"
#include "Platform.h"
#include "Background.h"

class Engine
{
public:
	Engine();
	void loop();
private:
	player playerCharacter_;
	Background background_;
	Platform platform_;
	
};
