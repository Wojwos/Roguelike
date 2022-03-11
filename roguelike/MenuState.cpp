#include "MenuState.h"

MenuState::MenuState(Game &game): game(game), background("Resources/Background.jpg")
{
	delay = 200;
	arrowy = 100;
}

void MenuState::init()
{
	textures.push_back(new sf::Texture());
	textures[0]->loadFromFile("Resources/newgame.png");
	textures.push_back(new sf::Texture());
	textures[1]->loadFromFile("Resources/exit.png");
	textures.push_back(new sf::Texture());
	textures[2]->loadFromFile("Resources/leftArrow.png");
	textures.push_back(new sf::Texture());
	textures[3]->loadFromFile("Resources/rightArrow.png");
	sprite = new sf::Sprite();
}

void MenuState::draw(sf::RenderWindow *window)
{
	background.draw(window);
	sprite->setTexture(*textures[0]);
	sprite->setPosition(200,100);
	window->draw(*sprite);
	sprite->setTexture(*textures[1]);
	sprite->setPosition(200, 300);
	window->draw(*sprite);
	sprite->setTexture(*textures[2]);
	sprite->setPosition(100, arrowy);
	window->draw(*sprite);
	sprite->setTexture(*textures[3]);
	sprite->setPosition(600, arrowy);
	window->draw(*sprite);
}

void MenuState::update(sf::RenderWindow *window)
{
	if (enter)
	{
		if (currentChoice == NEWGAME)
		{
			game.setState(Game::LEVELSTATE);
		}
		else if (currentChoice == EXIT)
			window->close();
	}
	if (delay < clock.getElapsedTime().asMilliseconds() || unlock)
	{
		if (arrowUp)
		{
			if (arrowy == 100)
			{
				arrowy = 300;
				currentChoice = EXIT;
			}
			else if (arrowy == 300)
			{
				arrowy = 100;
				currentChoice = NEWGAME;
			}
			clock.restart();
			unlock = false;
		}
		else if (arrowDown)
		{
			if (arrowy == 100)
			{
				arrowy = 300;
			currentChoice = EXIT;
			}
			else if (arrowy == 300)
			{
				arrowy = 100;
			currentChoice = NEWGAME;
			}
			clock.restart();
			unlock = false;
		}
	}
	else if (!arrowUp && !arrowDown)
		unlock = true;
}

void MenuState::keyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Enter) enter = true;
	if (key == sf::Keyboard::Up) arrowUp = true;
	if (key == sf::Keyboard::Down) arrowDown = true;
}

void MenuState::keyReleased(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Enter) enter = false;
	if (key == sf::Keyboard::Up) arrowUp = false;
	if (key == sf::Keyboard::Down) arrowDown = false;
}