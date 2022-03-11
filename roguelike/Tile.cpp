#include "Tile.h"

Tile::Tile(sf::Sprite *sp, int type)
{
	this->tileSprite = sp;
	this->tileType = type;
}

int Tile::getType()
{
	return tileType;
}

sf::Sprite* Tile::getImage()
{
	return tileSprite;
}