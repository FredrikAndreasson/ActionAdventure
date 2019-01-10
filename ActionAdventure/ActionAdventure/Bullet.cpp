#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(float anX, float aY, sf::RectangleShape aRectangle, float anAngle, float aSpeed)
{
	myShape = aRectangle;
	myShape.setFillColor(sf::Color::Blue);
	myShape.setPosition(anX, aY);
	myAngle = anAngle;
	mySpeed = aSpeed;
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	myShape.move(cos(myAngle) * mySpeed, 0);
	myShape.move(0, sin(myAngle) * mySpeed);
}