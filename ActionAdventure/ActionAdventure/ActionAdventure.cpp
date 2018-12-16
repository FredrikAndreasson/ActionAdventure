// CrossActionAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <sstream>
#include <string>
#include "Animation.h"

int main()
{

	Player myPlayer;
	Enemy* myEnemy;
	myEnemy = new Enemy();
	std::vector<Bullet*> myBulletVector;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
	sf::Texture myPlayerWalkTexture;
//myPlayerWalkTexture.loadFromFile("Textures\\PlayerAnimations\\PlayerWalk.PNG")

	if (!myPlayerWalkTexture.loadFromFile("D:/GitHub/ActionAdventure/ActionAdventure/Textures/PlayerAnimations/PlayerWalk"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	Animation myAnimations(&myPlayerWalkTexture, sf::Vector2u(32, 1), 0.1f, 4);
	myPlayer.myShape.setTexture(&myPlayerWalkTexture);
	int myFireRate = 100;
	int myChangeFPSString = 30;
	float myDeltaTime;
	sf::Clock myClock;


	sf::Text myHit;
	sf::Font myFont;
	myFont.loadFromFile("angelina.ttf");
	myHit.setFont(myFont);
	myHit.setString("HIT");
	myHit.setCharacterSize(52);
	myHit.setFillColor(sf::Color::Blue);
	myHit.setStyle(sf::Text::Bold);
	myHit.setPosition(50.f, 200.f);

	while (window.isOpen())
	{
		myDeltaTime = myClock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(150, 150, 150));
		window.draw(myEnemy->myShape);
		for (size_t i = myBulletVector.size(); i > 0; i--)
		{
			window.draw(myBulletVector[i - 1]->myShape);
			myBulletVector[i - 1]->Update();
		}
//Animations
myAnimations.Update(0, myDeltaTime);
myPlayer.myShape.setTextureRect(myAnimations.myUvRect);
window.draw(myPlayer.myShape);

//collision
for (size_t i = myBulletVector.size(); i > 0; i--)
{
	if (myBulletVector[i - 1]->myShape.getGlobalBounds().intersects(myEnemy->myShape.getGlobalBounds()))
	{
		window.draw(myHit);
	}
}
if (myPlayer.myShape.getGlobalBounds().intersects(myEnemy->myShape.getGlobalBounds()))
{
	window.draw(myHit);
}

window.display();
//Keybinds
if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
{
	myPlayer.myShape.move(0, -0.3f);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
{
	myPlayer.myShape.move(-0.3f, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
{
	myPlayer.myShape.move(0, 0.3f);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
{
	myPlayer.myShape.move(0.3f, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && myFireRate < 0)
{
	Bullet *tempBullet = new Bullet();

	myBulletVector.push_back(tempBullet);
	myBulletVector[myBulletVector.size() - 1]->Init(myPlayer.myShape.getPosition().x, myPlayer.myShape.getPosition().y,
		sf::RectangleShape(sf::Vector2f(10.0f, 10.0f)));
	myFireRate = 30;
}
else
{
	myFireRate--;
}

//Kill bullets outside of screen
for (size_t i = myBulletVector.size(); i > 0; i--)
{
	if (myBulletVector[i - 1]->myShape.getPosition().x < 0)
	{
		delete myBulletVector[i - 1];
		myBulletVector[i - 1] = NULL;
		myBulletVector.erase(myBulletVector.begin() + i - 1);
	}
}
	}
}
