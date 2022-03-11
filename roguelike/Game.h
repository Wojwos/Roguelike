#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "MenuState.h"
#include "LevelState.h"

class Game
{
public:
	static const int MENUSTATE = 0;
	static const int LEVELSTATE = 1;
	Game();
	void setState(int state);
	void init();
	void update(sf::RenderWindow * window);
	void draw(sf::RenderWindow * window);
	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);
	~Game(){}
private:
	int currentState;
	std::vector<GameState*> states;
};

#endif