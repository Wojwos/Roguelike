#include "Background.h"

Background::Background(std::string s)
{
	texture = new sf::Texture;
	texture->loadFromFile(s);
	sprite = new sf::Sprite;
	sprite->setTexture(*texture);
}

void Background::draw(sf::RenderWindow *window)
{
	sprite->setPosition(x,y);
	window->draw(*sprite);
}

Background::~Background()
{

}