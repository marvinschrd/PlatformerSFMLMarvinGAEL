#pragma once
#include "player.h"
#include "Platform.h"
#include "Background.h"
#include "Trap.h"
#include "WinObject.h"

class Engine;

class PlatformContactListener : public b2ContactListener
{
public:
	PlatformContactListener(Engine* engine);
	/// Called when two fixtures begin to touch.
	void BeginContact(b2Contact* contact) override;

	/// Called when two fixtures cease to touch.
	void EndContact(b2Contact* contact) override;

private:
	Engine* engine_ = nullptr;
};

class Engine
{
public:
	Engine();
	void loop();
	void OnContactEnter(b2Fixture* c1, b2Fixture* c2);
	void OnContactExit(b2Fixture* c1, b2Fixture* c2);
	/*void OnContactWin(b2Fixture* c1, b2Fixture* c2);*/
private:
	Engine* engine_ = nullptr;
	player playerCharacter_;
	Background background_;
	Trap trap_;
	WinObject winObject_;
	Platform platform_;
	PlatformContactListener platformListener_;
	
};
