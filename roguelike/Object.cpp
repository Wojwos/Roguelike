#include "Object.h"

Object::Object(TileMap *tileMap): tileMap(tileMap)
{
	this->tileSize = tileMap->getTileSize();
}

void Object::checkMapCollisions()
{
	leftTile = (int)(xtemp) / tileSize;
	rightTile = (int)(xtemp + width) / tileSize;
	topTile = (int)y / tileSize;
	botTile = (int)(y + height - 1) / tileSize;

	for (int row = topTile; row <= botTile; row++)
	{
		if (tileMap->getTileType(row, leftTile) == Tile::BLOCK)
		{
			dx = 0;
			x = (leftTile + 1) * tileSize;
		}
		if (tileMap->getTileType(row, rightTile) == Tile::BLOCK)
		{
			dx = 0;
			x = (rightTile) * tileSize - 1 - width;
		}
	}

	leftTile = (int)x / tileSize;
	rightTile = (int)(x + width) / tileSize;
	topTile = (int)ytemp / tileSize;
	botTile = (int)(ytemp + height - 1) / tileSize;

	for (int col = leftTile; col <= rightTile; col++)
	{
		
		if (tileMap->getTileType(topTile, col) == Tile::BLOCK)
		{
			dy = 0;
			y = (topTile + 1) * tileSize;
		}
		if (tileMap->getTileType(botTile, col) == Tile::BLOCK)
		{
			dy = 0;
			falling = false;
			y = botTile * tileSize - height;
		}
	}

	botTile = (int)(y + height + 1) / tileSize;
	for (int col = leftTile; col <= rightTile; col++)
	{
		if (tileMap->getTileType(botTile, col) == Tile::BLOCK)
		{
			falling = false;
			break;
		}
		else
			falling = true;
	}
}