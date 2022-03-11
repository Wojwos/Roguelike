#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"
#include "Weapon.h"
#include "Zombie.h"
#include "Archer.h"
#include "Melee.h"
#include "TileMap.h"
#include "Background.h"
#include "MenuState.h";

int main()
{
	Game game;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Roguelike");
	window.setFramerateLimit(60);
	game.init();

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				game.keyPressed(event.key.code);
			}
			if (event.type == sf::Event::KeyReleased) {
				game.keyReleased(event.key.code);
			}
		}
		window.clear();
		game.update(&window);
		game.draw(&window);
		window.display();
	}
	return 0;
}