#include "Enemy.h"

Enemy::Enemy(TileMap *tileMap): Object(tileMap)
{

}

void Enemy::setDamaged(bool set)
{
	damaged = set;
}

bool Enemy::wasDamaged()
{
	return damaged;
}

int Enemy::getDamage()
{
	return damage;
}

bool Enemy::isDead()
{
	return dead;
}

void Enemy::hit(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
	if (health == 0)
		dead = true;
}