#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Object.h"
#include "Enemy.h"

class Player: public Object
{
public:
	Player(TileMap *tileMap);
	void draw(sf::RenderWindow *window);
	void checkAttack(std::vector<Enemy*> &enemies);
	void update();
	void setAction();
	void getNextPos();

	~Player() {}

private:
	sf::Clock clock;
	sf::IntRect *playerRect;
	sf::Texture *playerTexture;
	sf::Sprite *playerSprite;

	//movement speed
	const float maxFallingSpeed = 15;
	const float maxMovingSpeed = 4;

	//animations
	Animation animation;
	const int numFrames[4] = { 10,6,6,8 };
	std::vector<sf::IntRect*> *actionFrames;
	std::vector<std::vector<sf::IntRect*>*> frames;

	//actions delay
	long attackingDelay = 0;
	long jumpingDelay = 0;

	//actions lock
	bool jumpingLock = false;
	bool attackingLock = false;

	//timers
	sf::Clock attackingTimer;
	sf::Clock jumpingTimer;

	//sprite type
	const int ATTACKING = 0;
	const int IDLE = 1;
	const int JUMPING = 2;
	const int MOVING = 3;
	int currentAction = 0;

	//sprite direction
	const int facingLeft = 0;
	const int facingRight = 1;
	int direction = 1;

	//weapon
	double wx = 0;
	double wy = 0;
	int wwidth = 0;
	int wheight = 0;

	int damage = 0;
	
};

#endif