#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#define _USE_MATH_DEFINES

#include <cmath>
#include <SFML/Graphics.hpp>
#include "Player.h"
class Enemy
{
public:
	Enemy(float aSpeed, float someHealth, int someDamage);
	~Enemy();

	enum AnimationState{Fly, Attack, Death};
	AnimationState myAnimationState;
	sf::RectangleShape myShape;

	void Update(Player* aPlayer);

private: 
	bool myCollided;
	float myAcceleration;
	float myCurrentSpeed;
	float myMaxSpeed;
	float myHealth;
	float myAngle;
	int myDamage;
};
#endif