#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "Game.h"
#include "Background.h"
#include <vector>

class MenuState : public GameState
{
public:
	class Game &game;
	MenuState(Game &game);
	void init();
	void update(sf::RenderWindow *window);
	void draw(sf::RenderWindow *window);
	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);
	~MenuState() {}

private:
	const int NEWGAME = 0;
	const int EXIT = 1;
	int currentChoice = 0;

	int arrowy = 0;

	long delay = 0;
	bool unlock = false;

	sf::Clock clock;

	bool arrowUp = false;
	bool arrowDown = false;
	bool enter = false;

	Background background;
	std::vector<sf::Texture*> textures;
	sf::Sprite *sprite;
};

#endif