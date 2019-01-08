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
#include "HealthUI.h"

int main()
{
	bool pressed = false;
	Player myPlayer(100, 10, 0, 100, 1, 3);
	Enemy* myEnemy;
	myEnemy = new Enemy();
	std::vector<Bullet*> myBulletVector;
	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
	sf::Texture myPlayerWalkDownStrip;
	if (!myPlayerWalkDownStrip.loadFromFile("Textures/PlayerAnimations/PlayerWalkDown8.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myPlayerWalkRightStrip;
	if (!myPlayerWalkRightStrip.loadFromFile("Textures/PlayerAnimations/PlayerWalkRight8.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myPlayerWalkLeftStrip;
	if (!myPlayerWalkLeftStrip.loadFromFile("Textures/PlayerAnimations/PlayerWalkLeft8.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myPlayerWalkUpStrip;
	if (!myPlayerWalkUpStrip.loadFromFile("Textures/PlayerAnimations/PlayerWalkUp8.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myBatFlyingStrip;
	if (!myBatFlyingStrip.loadFromFile("Textures/BatAnimations/BatFlyingStrip5.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myBatAttackStrip;
	if (!myBatAttackStrip.loadFromFile("Textures/BatAnimations/BatAttackStrip5.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myBatDeathStrip;
	if (!myBatDeathStrip.loadFromFile("Textures/BatAnimations/BatDeathStrip5.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}
	sf::Texture myHeartTexture;
	if (!myHeartTexture.loadFromFile("Textures/UITextures/Heart.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}	
	sf::Texture myHealthUITexture;
	if (!myHealthUITexture.loadFromFile("Textures/UITextures/HealthUI.png"))
	{
		std::cout << "Load Failed" << std::endl;
		system("pause");
	}



	Animation myPlayerDownAnimation(&myPlayerWalkDownStrip, sf::Vector2u(8, 1), 0.1f);
	myPlayer.myShape.setTexture(&myPlayerWalkDownStrip);
	HealthUI myHealthUI;
	myHealthUI.myHealthUIShape.setTexture(&myHealthUITexture);
	int myFireRate = 100;
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
		//Player
		myPlayerDownAnimation.Update(0, myDeltaTime);
		myPlayer.myShape.setTextureRect(myPlayerDownAnimation.myUvRect);
		window.draw(myPlayer.myShape);
		//Bat

		//HealthUI
		window.draw(myHealthUI.myHealthUIShape);
		myHealthUI.Update(&myPlayer);
		window.draw(myHealthUI.myHealthBar);
		window.draw(myHealthUI.myManaBar);

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && !pressed)
		{
			myPlayer.SetHealth(myPlayer.GetHealth() - 1);
			pressed = true;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::G) && pressed)
		{
			pressed = false;
		}

		//Player Update 
		myPlayer.Update();

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
