#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	myShape = sf::RectangleShape(sf::Vector2f(64.0f, 64.0f));
	//myShape.setFillColor(sf::Color::Green);
}


Player::~Player()
{}