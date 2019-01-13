#include "stdafx.h"
#include "Player.h"

Player::Player(float someHealth, int someDamage, int someSpellPower, float someMana, float someManaRegen, int someLives)
{
	//Define player size
	myShape = sf::RectangleShape(sf::Vector2f(64.0f, 64.0f));
	//Give values to stats
	myHealth = someHealth;
	myDamage = someDamage;
	mySpellPower = someSpellPower;
	myMana = someMana;
	myManaRegen = someManaRegen;
	myLives = someLives;
	mySpeed = 0.1f;
	myAnimationState = AnimationState::WalkUp;
	myFireRate = 100;
	myShape.setOrigin(32.0f, 32.0f);
}


Player::~Player()
{}

void Player::Update(sf::Vector2f aMousePosition)
{
	//Animation handling
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			myAnimationState = AnimationState::Idle;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			myAnimationState = AnimationState::WalkUp;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			myAnimationState = AnimationState::WalkDown;
		}
		else { myAnimationState = AnimationState::Idle; }
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myAnimationState = AnimationState::WalkLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myAnimationState = AnimationState::WalkRight;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myAnimationState = AnimationState::Idle;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myAnimationState = AnimationState::WalkUp;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myAnimationState = AnimationState::WalkDown;
	}
	else {	myAnimationState = AnimationState::Idle;}
	//Keybinds
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myShape.move(0, -mySpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myShape.move(-mySpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myShape.move(0, mySpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myShape.move(mySpeed, 0);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && myFireRate < 0)
	{
		float tempAngle = atan2(aMousePosition.y - myShape.getPosition().y, aMousePosition.x - myShape.getPosition().x);
		Bullet *tempBullet = new Bullet(myShape.getPosition().x, myShape.getPosition().y, sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)),tempAngle, 0.2f);

		myBulletVector.push_back(tempBullet);
		myFireRate = 300;
	}
	else
	{
		myFireRate--;
	}
}

float Player::GetHealth()
{
	return myHealth;
}
float Player::GetMana()
{
	return myMana;
}
float Player::GetManaRegen()
{
	return myManaRegen;
}
int Player::GetSpellPower()
{
	return mySpellPower;
}
int Player::GetDamage()
{
	return myDamage;
}
int Player::GetLives()
{
	return myLives;
}

void Player::SetHealth(float aValue)
{
	myHealth = aValue;
}
void Player::SetMana(float aValue)
{
	myMana = aValue;
}
void Player::SetManaRegen(float aValue)
{
	myManaRegen = aValue;
}
void Player::SetSpellPower(int aValue)
{
	mySpellPower = aValue;
}
void Player::SetDamage(int aValue)
{
	myDamage = aValue;
}
void Player::SetLives(int aValue)
{
	myLives = aValue;
}
