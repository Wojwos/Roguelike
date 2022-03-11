#include "Weapon.h"

Weapon::Weapon()
{

}

void Weapon::setPosition(double x, double y)
{
	weapon.setPosition(x,y);
}


void Weapon::drawWeapon(sf::RenderWindow &window)
{
	if (isUsed == 1)
		window.draw(weapon);
}

void Weapon::update()
{

}