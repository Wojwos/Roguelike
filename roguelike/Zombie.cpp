#include "Zombie.h"

Zombie::Zombie(TileMap *tileMap): Enemy(tileMap)
{
	spWidth = 32;
	spHeight = 32;
	width = 8;
	height = 32;
	spx = x - 13;
	spy = y;

	health = maxHealth = 5;

	attackingDelay = 800;

	enemyTexture = new sf::Texture;
	enemySprite = new sf::Sprite;
	enemyTexture->loadFromFile("Resources/Zombie_01.png");
	enemySprite->setTexture(*enemyTexture);
	for (int i = 0; i < 4; i++)
	{
		actionFrames = new std::vector<sf::IntRect*>;
		for (int j = 0; j < numFrames[i]; j++)
		{
			actionFrames->push_back(new sf::IntRect(j*spWidth, i*spHeight, spWidth, spHeight));
		}
		frames.push_back(&*actionFrames);
		actionFrames = NULL;
	}
	currentAction = MOVING;
	animation.setFrames(&*frames.at(MOVING));
	animation.setDelay(200);
	enemyRect = new sf::IntRect();
}

void Zombie::draw(sf::RenderWindow *window)
{
	enemyRect = animation.getImage();
	enemySprite->setTextureRect(*enemyRect);
	if (direction == facingLeft)
	{
		enemySprite->setOrigin({ enemySprite->getLocalBounds().width, 0 });
		enemySprite->setScale({ -1, 1 });
	}
	else
	{
		enemySprite->setOrigin({ 0, 0 });
		enemySprite->setScale({ 1, 1 });
	}
	window->draw(*enemySprite);
}

void Zombie::setAction()
{
	if (attacking && currentAction != ATTACKING)
	{
		if (attackingDelay < attackingTimer.getElapsedTime().asMilliseconds())
		{
			if (currentAction != ATTACKING)
			{
				currentAction = ATTACKING;
				animation.setFrames(&*frames.at(ATTACKING));
				animation.setDelay(200);
				attackingTimer.restart();
			}
		}
	}
	else if ((currentAction == ATTACKING && animation.hasPlayedOnce()) || currentAction != ATTACKING)
	{
		if (dy == 0)
		{
			if (dx == 0)
			{
				if (currentAction != DIGGING)
				{
					currentAction = DIGGING;
					animation.setFrames(&*frames.at(DIGGING));
					animation.setDelay(400);
				}
			}
			else if (dx > 0 || dx < 0)
			{
				if (currentAction != MOVING)
				{
					currentAction = MOVING;
					animation.setFrames(&*frames.at(MOVING));
					animation.setDelay(100);
				}
			}
		}
		else if (dy != 0)
		{
			if (currentAction != DYING)
			{
				currentAction = DYING;
				animation.setFrames(&*frames.at(DYING));
				animation.setDelay(100);
			}
		}
	}
		if (dx > 0)
			direction = facingRight;
		else if (dx < 0)
			direction = facingLeft;
}

void Zombie::update()
{
	getNextPos();
	checkMapCollisions();
	setAction();
	animation.update();
	x += dx;
	y += dy;
	if (tileMap->getTileType((int)(y + height + 1) / tileSize, (int)(x + width + 1) / tileSize) == Tile::EMPTY)
	{
		dx = 0;
	}
	if (tileMap->getTileType((int)(y + height + 1) / tileSize, (int)(x - 1) / tileSize) == Tile::EMPTY)
	{
		dx = 0;
	}
	if (dx == 0 && direction == facingLeft)
	{
		left = false;
		right = true;
		direction = facingRight;
	}
	else if (dx == 0 && direction == facingRight)
	{
		left = true;
		right = false;
		direction = facingLeft;
	}
	spx = x - 13;
	spy = y;
	enemySprite->setPosition(spx, spy);
}

void Zombie::getNextPos()
{
	if (left)
		dx = -maxMovingSpeed;
	else if (right)
		dx = maxMovingSpeed;
	else
		dx = 0;
	
	if (falling)
	{
		dy += 0.2;
		if (dy > maxFallingSpeed)
			dy = maxFallingSpeed;
	}

	xtemp = x + dx;
	ytemp = y + dy;
}