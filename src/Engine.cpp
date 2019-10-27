#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Platform.h"


Engine::Engine()
{
}

void Engine::loop()
{
	sf::RenderWindow window(sf::VideoMode(800, 501), "My window");
	window.setVerticalSyncEnabled(true);

	

	b2World world(b2Vec2(0.0f, 9.81f));

	playerCharacter_.init(world);
	platform_.Init(world);
	

	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		// c'est ici qu'on dessine tout
		// window.draw(...);
		//background_.DrawBackground(window);
		//platform_.DrawPlatform(window);
		playerCharacter_.DrawPlayer(window);
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}
}
