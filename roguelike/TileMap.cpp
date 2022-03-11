#include "TileMap.h"

TileMap::TileMap(const int tileSize)
{
	this->tileSize = tileSize;
	numRows = 10;
	numCol = 26;
	numRooms = 8;
}

void TileMap::loadTiles(std::string fileName)
{
	tileTexture = new sf::Texture();
	tileTexture->loadFromFile(fileName);
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCol*numRooms; col++)
		{
			tileSprite = new sf::Sprite();
			tileSprite->setTexture(*tileTexture);
			if (map[row][col] == Tile::EMPTY || (col != 0 && col != numCol* numRooms-1 && (col % 26 == 0 || col % 26 == 25) && (row == 7 || row == numRooms)))
			{
				tileSprite->setTextureRect(sf::IntRect(0, 0, tileSize, tileSize));
				tiles[row][col] = new Tile(tileSprite, Tile::EMPTY);
			}
			else if(map[row][col] = Tile::BLOCK)
			{
				tileSprite->setTextureRect(sf::IntRect(50, 0, tileSize, tileSize));
				tiles[row][col] = new Tile(tileSprite, Tile::BLOCK);
			}
			else if (map[row][col] = Tile::PLATFORM)
			{
				tileSprite->setTextureRect(sf::IntRect(100, 0, 50, 50));
				tiles[row][col] = new Tile(tileSprite, Tile::PLATFORM);
			}
		}
	}
}

void TileMap::loadMap(int seed[8], std::string fileName)
{
	std::fstream stream;
	stream.open(fileName);
	try
	{
		std::string e = "Map file doesn't exist!";
		if (stream.fail())
		throw e;
	}
	catch (std::string e)
	{
		std::cout << e <<std::endl;
	}
	std::string s;
	/*while (!stream.eof())
	{
		getline(stream,s);
		numRows++;
	}
	numCol = s.size();
	stream.close();
	stream.open(fileName);*/
	for (int room = 0; room < numRooms; room++)
	{
		for (int i = 0; i < seed[room]; i++)
		{
			for (int j = 0; j < numRows; j++)
				std::getline(stream, s);
		}
		for (int row = 0; row < numRows; row++)
		{
			std::getline(stream, s);
			std::stringstream iss(s);
			char valChar;
			int value;
			for (int col = 0; col < numCol; col++)
			{
				iss >> valChar;
				value = valChar - '0';
				map[row][col + 26 * room] = value;
			}
		}
		stream.clear();
		stream.seekg(0);
	}
	stream.close();
	/*
	if (roomType == standard)
	{
		width = 100;
		height = 50;
	}
	else if (roomType == tunnel)
	{
		width = 100;
		height = 20;
	}
	else if (roomType == elevator)
	{
		width = 20;
		height = 100;
	}
	*/

}

void TileMap::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCol*numRooms; j++)
		{
			mapSprite = tiles[i][j]->getImage();
			mapSprite->setPosition(j*tileSize,i*tileSize);
			window->draw(*mapSprite);
		}
	}

}

int TileMap::getTileType(int row, int col)
{
	return tiles[row][col]->getType();
}

int TileMap::getTileSize()
{
	return tileSize;
}