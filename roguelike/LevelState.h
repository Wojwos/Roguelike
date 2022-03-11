#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "Game.h"
#include "TileMap.h"
#include "Player.h"
#include "Zombie.h"
#include "Archer.h"

class LevelState : public GameState
{
public:
	class Game &game;
	LevelState(Game &game);
	void init();
	void update(sf::RenderWindow *window);
	void draw(sf::RenderWindow *window);
	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);
	~LevelState() {}
private:
	int seed[8] = { 0 };

	std::vector<Enemy*> enemies;
	TileMap *tileMap;
	Player *player; 
	sf::View *view;
};


#endif