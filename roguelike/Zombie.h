#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "SFML/Graphics.hpp"
#include "Enemy.h"
#include "Player.h"

class Zombie : public Enemy
{
public:
	Zombie(TileMap *tileMap);
	void draw(sf::RenderWindow *window);
	void setAction();
	void update(); 
	void getNextPos();
	~Zombie() {}
private:

	//animations
	Animation animation;
	const int numFrames[4] = { 4, 4, 4, 4 };
	std::vector<sf::IntRect*> *actionFrames;
	std::vector<std::vector<sf::IntRect*>*> frames;

	//actions delay
	long attackingDelay = 0;
	long jumpingDelay = 0;

	//movement speed
	const float maxFallingSpeed = 15;
	const float maxMovingSpeed = 1;

	//sprite type
	const int MOVING = 0;
	const int ATTACKING = 1;
	const int DIGGING = 2;
	const int DYING = 3;
	int currentAction = 0;
};

#endif