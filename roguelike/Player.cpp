#include "Player.h"
#include <iostream>

Player::Player(TileMap *tileMap): Object(tileMap)
{
	spWidth = 64;
	spHeight = 64;
	width = 10;
	height = 20;
	x = 40;
	y = 160;
	spx = x - 27;
	spy = y - 28;
	
	damage = 5;
	wwidth = 24;
	wheight = 39;

	attackingDelay = 800;

	playerTexture = new sf::Texture;
	playerSprite = new sf::Sprite;
	playerTexture->loadFromFile("Resources/player.png");
	playerSprite->setTexture(*playerTexture);
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
	currentAction = IDLE;
	animation.setFrames(&*frames.at(IDLE));
	animation.setDelay(150);
	playerRect = new sf::IntRect();
}

void Player::draw(sf::RenderWindow *window)
{
	playerRect = animation.getImage();
	playerSprite->setTextureRect(*playerRect);
	if (direction == facingLeft)
	{
		playerSprite->setOrigin({ playerSprite->getLocalBounds().width, 0 });
		playerSprite->setScale({ -1, 1 });
	}
	else
	{
		playerSprite->setOrigin({ 0, 0 });
		playerSprite->setScale({ 1, 1 });
	}
	window->draw(*playerSprite);
}

void Player::checkAttack(std::vector<Enemy*> &enemies)
{
	if (currentAction == ATTACKING && animation.getFrame() >= 5 && !animation.hasPlayedOnce())
	{
		if (direction == facingRight)
		{
			wx = x + width;
			wy = y - 19;
		}
		else if (direction == facingLeft)
		{
			wx = x - wwidth;
			wy = y - 19;
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i]->wasDamaged())
			{
				if (enemies[i]->getY() < wy + wheight && enemies[i]->getY() + enemies[i]->getHeight() > wy)
				{
					if (direction == facingRight)
					{
						if ((enemies[i]->getX() > wx && enemies[i]->getX() < wx + wwidth) || (enemies[i]->getX() + enemies[i]->getWidth() > wx && enemies[i]->getX() + enemies[i]->getWidth() < wx + wwidth))
						{
							enemies[i]->hit(damage);
							enemies[i]->setDamaged(true);
						}
					}
					else if (direction == facingLeft)
					{
						if ((enemies[i]->getX() > wx && enemies[i]->getX() < wx + wwidth) || (enemies[i]->getX() + enemies[i]->getWidth() > wx && enemies[i]->getX() + enemies[i]->getWidth() < wx + wwidth))
						{
							enemies[i]->hit(damage);
							enemies[i]->setDamaged(true);
						}
					}
				}
			}
		}
	}
	if (currentAction == ATTACKING && animation.hasPlayedOnce())
	{
		for (int i = 0; i < enemies.size(); i++)
			enemies[i]->setDamaged(false);
	}
}

void Player::setAction()
{
	if (attacking && currentAction != ATTACKING)
	{
		if (attackingDelay < attackingTimer.getElapsedTime().asMilliseconds())
		{
			if (currentAction != ATTACKING)
			{
				currentAction = ATTACKING;
				animation.setFrames(&*frames.at(ATTACKING));
				animation.setDelay(40);
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
				if (currentAction != IDLE)
				{
					currentAction = IDLE;
					animation.setFrames(&*frames.at(IDLE));
					animation.setDelay(150);
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
			if (currentAction != JUMPING)
			{
				currentAction = JUMPING;
				animation.setFrames(&*frames.at(JUMPING));
				animation.setDelay(100);
			}
		}
	}
	//if (currentAction != ATTACKING)
	//{
		if (dx > 0)
			direction = facingRight;
		else if (dx < 0)
			direction = facingLeft;
	//}
}


void Player::update()
{
	getNextPos();
	checkMapCollisions();
	setAction();
	animation.update();
	x += dx;
	y += dy;
	spx = x - 27;
	spy = y - 28;
	playerSprite->setPosition(spx, spy);
}

void Player::getNextPos()
{
	if (left)
		dx = -maxMovingSpeed;
	else if (right)
		dx = maxMovingSpeed;
	else
		dx = 0;
	if (jumping && falling)
		jumping = false; 
	if (!jumping && !falling) 
		jumpingLock = false;
	if (!jumpingLock)
	{
		if (jumping && !falling)
		{
			dy = -5;
			falling = true;
			jumpingLock = true;
		}
	}

	if (falling)
	{
		dy += 0.2;
		if (dy >= 0)
			jumping = false;
		if (dy > maxFallingSpeed)
			dy = maxFallingSpeed;
	}

	xtemp = x + dx;
	ytemp = y + dy;
}