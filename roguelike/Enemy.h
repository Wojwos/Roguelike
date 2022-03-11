#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "Object.h"
//#include "Player.h"

class Enemy: public Object
{
public:
	Enemy(TileMap *tileMap);
	bool isDead();
	void hit(int damage);
	void setDamaged(bool set);
	int getDamage();
	bool wasDamaged();
	virtual void update() {}
	virtual void draw(sf::RenderWindow *window) {}
	~Enemy() {}
protected:
	sf::Clock clock;
	sf::IntRect *enemyRect;
	sf::Texture *enemyTexture;
	sf::Sprite *enemySprite;

	//timers
	sf::Clock attackingTimer;
	sf::Clock jumpingTimer;

	//sprite direction
	const int facingLeft = 0;
	const int facingRight = 1;
	int direction = 1;

	bool dead = 0;
	int damage = 0;
	bool damaged = false;
};

#endif