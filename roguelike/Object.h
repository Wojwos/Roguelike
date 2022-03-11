#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "TileMap.h"

class Object
{
public:
	Object(TileMap *tileMap);

	void checkMapCollisions();

	//set actions
	void setRight(bool set) { right = set; }
	void setLeft(bool set) { left = set; }
	void setJumping(bool set) {jumping = set;}
	void setCrouching(bool set) { crouching = set; }
	void setAttacking(bool set) { attacking = set; }

	double getX() { return x; }
	double getY() { return y; }
	double getWidth() { return width; }
	double getHeight() { return height; }

	void setPosition(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	void setVector(double dx, double dy)
	{
		this->dx = dx;
		this->dy = dy;
	}

	~Object() {}

protected:
	//actions
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
	bool jumping = false;
	bool falling = false;
	bool crouching = false;
	bool attacking = false;

	int maxHealth = 0;
	int health = 0;

	//position
	double xtemp = 0, ytemp = 0;
	double x = 0, y = 0;
	double spx = 0, spy = 0;
	double dx = 0, dy = 0;

	int leftTile = 0, rightTile = 0;
	int botTile = 0, topTile = 0;

	int width = 0, height = 0;
	int spWidth = 0, spHeight = 0;

	TileMap *tileMap;
	int tileSize = 0;
};

#endif