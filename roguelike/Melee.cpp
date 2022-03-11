#include "Melee.h"

Melee::Melee(sf::Vector2f size)
{
	weapon.setSize(size);
	weapon.setFillColor(sf::Color::Yellow);
}

void Melee::drawWeapon(sf::RenderWindow &window)
{
	if (isUsed == 1)
		window.draw(weapon);
}

void Melee::setPos(sf::Vector2f newPos)
{
	newPos.x = newPos.x + 40;
	newPos.y = newPos.y - 30;
	weapon.setPosition(newPos);
}

void Melee::use(sf::RenderWindow &window)
{
	isUsed = 1;
	drawWeapon(window);
}

void Melee::update()
{

}