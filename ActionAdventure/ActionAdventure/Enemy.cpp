#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	myShape = sf::CircleShape(100.f);
	myShape.setFillColor(sf::Color::Red);
}


Enemy::~Enemy()
{
}