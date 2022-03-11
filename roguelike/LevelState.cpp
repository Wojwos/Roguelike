#include "LevelState.h"
#include <thread>

LevelState::LevelState(Game &game) : game(game)
{
	init();
}

void LevelState::init()
{
	srand(time(NULL));
	seed[0] = (rand() % 8);  
	seed[1] = (rand() % 8); 
	seed[2] = (rand() % 8);  
	seed[3] = (rand() % 8);
	seed[4] = (rand() % 8);
	seed[5] = (rand() % 8);
	seed[6] = (rand() % 8);
	seed[7] = (rand() % 8);
	tileMap = new TileMap(20);
	tileMap->loadMap(seed, "Resources/map.txt");
	tileMap->loadTiles("Resources/tiles.png");

	player = new Player(tileMap);
	view = new sf::View(sf::FloatRect(0.f, -280.f, 800.f, 600.f));
	view->zoom(0.5);
	int q = 0; 
	int p = 0;


	/*
	for (int i = 0; i < 16; i++)
	{
		if (p > 2)
			p = 0;
		q = (rand() % 2);
		if (q == 0)
			enemies.push_back(new Zombie(tileMap));
		else
			enemies.push_back(new Archer(tileMap));
		enemies[i]->setPosition(140 + 520 * (i / 2), 80*p);
		p++;
	}
	*/
	std::thread t[16];
	for (int i = 0; i < 16; i++)
	{
		if (p > 2)
			p = 0;
		q = (rand() % 2);
		if (q == 0)
			enemies.push_back(new Zombie(tileMap));
		else
			enemies.push_back(new Archer(tileMap));
		t[i] = std::thread(&Enemy::setPosition,enemies[i], 140 + 520 * (i / 2), 80 * p);
	}
	for (int i = 0; i < 16; ++i)
	{
		t[i].join();
	}
}

void LevelState::update(sf::RenderWindow *window)
{
	player->checkAttack(enemies);
	player->update();
	for (std::vector<Enemy*>::iterator i = enemies.begin(); i != enemies.end(); i++)
	{
		(*i)->update();
	}
	view->setCenter(player->getX(), player->getY());
}

void LevelState::draw(sf::RenderWindow *window)
{
	window->setView(*view);
	tileMap->draw(window);
	for (int i = 0; i < enemies.size(); i++)
	{
		if(!enemies[i]->isDead())
			enemies[i]->draw(window);
	}
	player->draw(window);
}

void LevelState::keyPressed(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left) player->setLeft(true);
	if (key == sf::Keyboard::Right) player->setRight(true);
	if (key == sf::Keyboard::Up) player->setJumping(true);
	if (key == sf::Keyboard::Down) player->setCrouching(true);
	if (key == sf::Keyboard::Z) player->setAttacking(true);
}

void LevelState::keyReleased(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Left) player->setLeft(false);
	if (key == sf::Keyboard::Right) player->setRight(false);
	if (key == sf::Keyboard::Up) player->setJumping(false);
	if (key == sf::Keyboard::Down) player->setCrouching(false);
	if (key == sf::Keyboard::Z) player->setAttacking(false);
}