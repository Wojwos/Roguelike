#ifndef BLOCK_H
#define BLOCK_H

#include "SFML/Graphics.hpp"

class Tile
{
public:
	Tile(sf::Sprite *sp, int type);
	sf::Sprite* getImage();
	int getType();
	static const int EMPTY = 0;
	static const int BLOCK = 1;
	static const int PLATFORM = 2;
private:
	sf::Sprite *tileSprite;
	int tileType = 0;
};

#endif
