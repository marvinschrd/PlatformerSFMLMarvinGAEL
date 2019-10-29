#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Platform.h"


Engine::Engine() : platformListener_(this)
{
}

void Engine::loop()
{
	sf::RenderWindow window(sf::VideoMode(1000, 626), "Cat");
	window.setVerticalSyncEnabled(true);

	

	b2World world(b2Vec2(0.0f, 9.81f));
	world.SetContactListener(&platformListener_);

	spike_.init(world);
	playerCharacter_.init(world);
	platform_.Init(world);
	chest_.init(world);
	
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
			if(playerCharacter_.playerHealth_<=0||playerCharacter_.chestContact_==true)
			{
				window.close();
				
			}
		}
		playerCharacter_.Update(deltaTime.asSeconds());
		platform_.update();
		world.Step(deltaTime.asSeconds(), velocityIterations, positionIterations);
		window.clear(sf::Color::Black);
		// c'est ici qu'on dessine tout
		// window.draw(...);
		background_.DrawBackground(window);
		background_.DrawHeart(window, playerCharacter_.playerHealth_);
		platform_.DrawPlatform(window);
		chest_.drawChest(window);
		playerCharacter_.DrawPlayer(window);
		spike_.DrawSpikeBlock(window, playerCharacter_.setSpikeBlock);
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}
}


void Engine::OnContactEnter(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	GameObject* g3 = (GameObject*)(c2->GetUserData());
	
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER &&
		g2->GetGameObjectType() == GameObjectType::PLATFORM)
	{
		playerCharacter_.OnContactBegin();
	}
	if(g1->GetGameObjectType() == GameObjectType::SPIKE &&
		g2->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER)
	{
		playerCharacter_.OnSpikeContact();
	}
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER &&
		g2->GetGameObjectType() == GameObjectType::CHEST)
	{
		playerCharacter_.chestContact_ = true;
	}
	
}

void Engine::OnContactExit(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	//GameObject* g3 = (GameObject*)(c2->GetUserData());
	
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER &&
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