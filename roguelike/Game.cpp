#include "Game.h"

Game::Game()
{
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Roguelike");
	currentState = MENUSTATE;
	this->states.push_back(new MenuState(*this));
	this->states.push_back(new LevelState(*this));
}

void Game::setState(int state) 
{
	this->currentState = state;
}

void Game::init()
{
	this->states.at(this->currentState)->init();
}

void Game::update(sf::RenderWindow * window)
{
	this->states.at(this->currentState)->update(window);
}

void Game::draw(sf::RenderWindow * window)
{
	this->states.at(this->currentState)->draw(window);
}

void Game::keyPressed(sf::Keyboard::Key key)
{
	this->states.at(this->currentState)->keyPressed(key);
}

void Game::keyReleased(sf::Keyboard::Key key)
{
	this->states.at(this->currentState)->keyReleased(key);
}