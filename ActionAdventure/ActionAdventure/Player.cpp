#include "stdafx.h"
#include "Player.h"

Player::Player(int someHealth, int someDamage, int someSpellPower, int someMana, int someManaRegen, int someLives)
{
	//Define player size
	myShape = sf::RectangleShape(sf::Vector2f(64.0f, 64.0f));
	myHealthUIShape = sf::RectangleShape(sf::Vector2f(190.0f, 61.0f));
	myHealthUIShape.setPosition(10, 10);
	//Give values to stats
	myHealth = someHealth;
	myDamage = someDamage;
	mySpellPower = someSpellPower;
	myMana = someMana;
	myManaRegen = someManaRegen;
	myLives = someLives;
}


Player::~Player()
{}

void Player::Update()
{
	//Keybinds
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myShape.move(0, -0.3f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myShape.move(-0.3f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myShape.move(0, 0.3f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myShape.move(0.3f, 0);
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
