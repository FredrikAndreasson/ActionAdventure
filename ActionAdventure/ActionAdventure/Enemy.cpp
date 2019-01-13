
#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(float aSpeed, float someHealth, int someDamage)
{
	myShape = sf::RectangleShape(sf::Vector2f(32.0f, 32.0f));
	myShape.setPosition(500, 500);
	myAcceleration = aSpeed;
	myHealth = someHealth;
	myDamage = someDamage;
	myAnimationState = Fly;
	myCurrentSpeed = 0;
	myMaxSpeed = 0.2f;
	myCollided = false;
}


Enemy::~Enemy()
{
}

void Enemy::Update(Player * aPlayer)
{
	float tempPlayerY = aPlayer->myShape.getPosition().y;
	float tempPlayerX = aPlayer->myShape.getPosition().x;
	double tempXDistance = tempPlayerX - myShape.getPosition().x;
	double tempYDistance = tempPlayerY - myShape.getPosition().y;
	double tempDistanceToPlayer = sqrt(tempXDistance*tempXDistance + tempYDistance*tempYDistance);
	//Movement IDEK
	if (!myCollided && tempDistanceToPlayer < 450 && tempDistanceToPlayer > 80)
	{
		myAngle = atan2(tempPlayerY - myShape.getPosition().y, tempPlayerX - myShape.getPosition().x);
	}
	if (myShape.getGlobalBounds().intersects(aPlayer->myShape.getGlobalBounds()) && !myCollided)
	{
		myCollided = true;
		myCurrentSpeed = myCurrentSpeed * -1;
		myAngle += M_PI;
	}
	if (!myShape.getGlobalBounds().intersects(aPlayer->myShape.getGlobalBounds()))
	{
		myCollided = false;
	}
	if (tempDistanceToPlayer < 450 && tempDistanceToPlayer > 80)
	{
		if (myCurrentSpeed < myMaxSpeed)
		{
			myCurrentSpeed = myCurrentSpeed + myAcceleration*1.5;
		}
		myAnimationState = Attack;
		myShape.move(cos(myAngle) * myCurrentSpeed, 0);
		myShape.move(0, sin(myAngle) * myCurrentSpeed);
	}
	else if (tempDistanceToPlayer <= 80)
	{
		myAnimationState = Attack;
		myShape.move(cos(myAngle) * myCurrentSpeed, 0);
		myShape.move(0, sin(myAngle) * myCurrentSpeed);
	}
	else
	{
		myAnimationState = Fly;
	}

}
