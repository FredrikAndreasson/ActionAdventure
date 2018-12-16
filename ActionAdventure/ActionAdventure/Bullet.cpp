#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Init(float anX, float aY, sf::RectangleShape aRectangle)
{
	myShape = aRectangle;
	myShape.setFillColor(sf::Color::Blue);
	myShape.setPosition(anX, aY);
}

void Bullet::Update()
{
	myShape.move(-0.1f, 0.0f);
}