#ifndef MELEE_H
#define MELEE_H

#include "SFML/Graphics.hpp"
#include "Weapon.h"

class Melee : public Weapon
{
public:
	Melee(sf::Vector2f size);
	void drawWeapon(sf::RenderWindow &window);
	~Melee() {}
	void setPos(sf::Vector2f newPos);
	void use(sf::RenderWindow &window);
	void update();
};

#endif