#ifndef WEAPON_H
#define WEAPON_H

#include "SFML/Graphics.hpp"
#include "Weapon.h"

class Weapon
{
public:
	sf::RectangleShape weapon;
	int damage;
	bool isUsed = 0;
	Weapon();
	~Weapon() {}
	virtual void setPosition(double x, double y);
	void drawWeapon(sf::RenderWindow &window);
	virtual void update();
};

#endif