#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML\Graphics.hpp>
#include "Background.h"

class Background
{
public:
	Background(std::string s);
	void draw(sf::RenderWindow *window);
	~Background();
private:
	int x = 0, y = -200;
	sf::Texture *texture;
	sf::Sprite *sprite;
};

#endif
