#include "stdafx.h"
#include "HealthUI.h"


HealthUI::HealthUI()
{
	myHealthBar = sf::RectangleShape(sf::Vector2f(110.0f, 13.0f));
	myInitialHealthHeight = 13.0f;
	myInitialHealthWidth = 110.0f;

	myManaBar = sf::RectangleShape(sf::Vector2f(110.0f, 11.0f));
	myInitialManaHeight = 11.0f;
	myInitialManaWidth = 110.0f;

	myHealthUIShape = sf::RectangleShape(sf::Vector2f(190.0f, 61.0f));

	//Set positions
	myHealthUIShape.setPosition(10, 10);
	myHealthBar.setPosition(30, 30);
	myManaBar.setPosition(30, 50);

	//Set initial colours
	myHealthBar.setFillColor(sf::Color::Red);
	myManaBar.setFillColor(sf::Color::Blue);
}


HealthUI::~HealthUI()
{}

void HealthUI::Update(Player* aPlayer)
{
	//Health
	myHealthBar.setSize(sf::Vector2f((aPlayer->GetHealth() / 100)* myInitialHealthWidth, myInitialHealthHeight));

	//Mana
	myManaBar.setSize(sf::Vector2f((aPlayer->GetMana() / 100)* myInitialManaWidth, myInitialManaHeight));
}
