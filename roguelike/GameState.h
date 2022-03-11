#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "SFML/Graphics.hpp"

class GameState
{
public:
	GameState() {}
	virtual void init() {}
	virtual void update(sf::RenderWindow *window) {}
	virtual void draw(sf::RenderWindow *window) {}
	virtual void keyPressed(sf::Keyboard::Key key) {}
	virtual void keyReleased(sf::Keyboard::Key key) {}
	~GameState() {}
};

#endif