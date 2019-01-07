#include "stdafx.h"
#include "HealthUI.h"


HealthUI::HealthUI()
{
	myInitialHealthHeight = 12.0f;
	myInitialHealthWidth = 105.0f;
	myHealthBar = sf::RectangleShape(sf::Vector2f(myInitialHealthWidth, myInitialHealthHeight));

	myInitialManaHeight = 7.0f;
	myInitialManaWidth = 105.0f;
	myManaBar = sf::RectangleShape(sf::Vector2f(myInitialManaWidth, myInitialManaHeight));

	myHealthUIShape = sf::RectangleShape(sf::Vector2f(190.0f, 61.0f));

	//Set positions
	myHealthUIShape.setPosition(10, 10);
	myHealthBar.setPosition(75, 31);
	myManaBar.setPosition(75, 46);

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
