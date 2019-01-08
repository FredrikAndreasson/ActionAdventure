#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	myShape = sf::RectangleShape(sf::Vector2f(32.0f, 32.0f));
}


Enemy::~Enemy()
{
}