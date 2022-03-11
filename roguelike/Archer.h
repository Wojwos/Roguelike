#ifndef ARCHER_H
#define ARCHER_H

#include "SFML/Graphics.hpp"
#include "Enemy.h"
//#include "Player.h"

class Archer : public Enemy
{
public:
	Archer(TileMap *tileMap);
	void draw(sf::RenderWindow *window);
	void setAction();
	void update();
	void getNextPos();
	~Archer() {}
private:

	//animations
	Animation animation;
	const int numFrames[3] = { 4,8,5 };
	std::vector<sf::IntRect*> *actionFrames;
	std::vector<std::vector<sf::IntRect*>*> frames;

	//actions delay
	long attackingDelay = 0;
	long jumpingDelay = 0;

	//movement speed
	const float maxFallingSpeed = 15;
	const float maxMovingSpeed = 1;

	//sprite type
	const int IDLE = 0;
	const int MOVING = 1;
	const int ATTACKING = 2;
	int currentAction = 0;

};

#endif