#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Platform.h"
#include "Trap.h"
#include "WinObject.h"


Engine::Engine() : platformListener_(this)
{
}

void Engine::loop()
{
	sf::RenderWindow window(sf::VideoMode(800, 501), "My window");
	window.setVerticalSyncEnabled(true);

	int contactWin_ = 0;

	b2World world(b2Vec2(0.0f, 9.81f));
	world.SetContactListener(&platformListener_);
	
	playerCharacter_.init(world);
	platform_.Init(world);
	trap_.Init(world);
	winObject_.Init(world);
	
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		playerCharacter_.Update(deltaTime.asSeconds());
		world.Step(deltaTime.asSeconds(), velocityIterations, positionIterations);
		window.clear(sf::Color::Black);
		// c'est ici qu'on dessine tout
		// window.draw(...);
		background_.DrawBackground(window);
		background_.DrawHeart(window);
		trap_.DrawTrap(window);
		platform_.DrawPlatform(window);
		winObject_.DrawWinObject(window);
		playerCharacter_.DrawPlayer(window);
		//Fin du jeu si contact avec l'objet gagnant, fermeture de la fenêtre
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (contactWin_ > 0)
				window.close();
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}
}

void Engine::OnContactEnter(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER ||
		g2->GetGameObjectType() == GameObjectType::PLATFORM)
	{
		playerCharacter_.OnContactBegin();
	}

	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER ||
		g2->GetGameObjectType() == GameObjectType::WINOBJECT)
	{
		playerCharacter_.Win();
	}
}

void Engine::OnContactExit(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER ||
		g2->GetGameObjectType() == GameObjectType::PLATFORM)
	{
		playerCharacter_.OnContactEnd();
	}

}

PlatformContactListener::PlatformContactListener(Engine* engine) : engine_(engine)
{
}

void PlatformContactListener::BeginContact(b2Contact* contact)
{
	engine_->OnContactEnter(contact->GetFixtureA(), contact->GetFixtureB());
}

void PlatformContactListener::EndContact(b2Contact* contact)
{
	engine_->OnContactExit(contact->GetFixtureA(), contact->GetFixtureB());
}
