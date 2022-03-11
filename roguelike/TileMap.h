#ifndef MAP_H
#define MAP_H

#include "SFML/Graphics.hpp"
#include "Tile.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

class TileMap
{
public:
	TileMap(const int tileSize);
	void loadTiles(std::string fileName);
	void loadMap(int seed[8], std::string fileName);
	void draw(sf::RenderWindow *window);
	int getTileType(int x, int y);
	int getTileSize();
	~TileMap() {}

private:
	sf::Sprite *mapSprite;
	int map[1000][1000];
	Tile* tiles[1000][1000];
	sf::Texture* tileTexture;
	sf::Sprite* tileSprite;

	int tileSize = 0;

	int numRows = 0;
	int numCol = 0;
	int numRooms = 0;

};


#endif
