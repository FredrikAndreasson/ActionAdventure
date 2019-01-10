// CrossActionAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <sstream>
#include <string>
#include "Animation.h"
#include "HealthUI.h"

int main()
{
	bool pressed = false;
	Player myPlayer(100, 10, 0, 100, 1, 3);
	std::vector<Enemy*> myBatVector;
	Enemy* myEnemy;
	myEnemy = new Enemy(0.00015f,100,100);
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

	//player animation
	Animation myPlayerDownAnimation(&myPlayerWalkDownStrip, sf::Vector2u(8, 1), 0.1f);
	Animation myPlayerUpAnimation(&myPlayerWalkUpStrip, sf::Vector2u(8, 1), 0.1f);
	Animation myPlayerLeftAnimation(&myPlayerWalkLeftStrip, sf::Vector2u(8, 1), 0.1f);
	Animation myPlayerRightAnimation(&myPlayerWalkRightStrip, sf::Vector2u(8, 1), 0.1f);
	myPlayer.myShape.setTexture(&myPlayerWalkDownStrip);
	//Bat animation
	Animation myBatAttackAnimation(&myBatAttackStrip, sf::Vector2u(5, 1), 0.1f);
	Animation myBatFlyingAnimation(&myBatFlyingStrip, sf::Vector2u(5, 1), 0.1f);
	Animation myBatDeathAnimation(&myBatDeathStrip, sf::Vector2u(5, 1), 0.1f);
	myEnemy->myShape.setTexture(&myBatFlyingStrip);

	HealthUI myHealthUI;
	myHealthUI.myHealthUIShape.setTexture(&myHealthUITexture);
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
		for (size_t i = myPlayer.myBulletVector.size(); i > 0; i--)
		{
			window.draw(myPlayer.myBulletVector[i - 1]->myShape);
			myPlayer.myBulletVector[i - 1]->Update();
		}
		//Animations
		//Player
		if (myPlayer.myAnimationState == myPlayer.WalkDown)
		{
			myPlayerDownAnimation.Update(0, myDeltaTime);
			myPlayer.myShape.setTextureRect(myPlayerDownAnimation.myUvRect);
			myPlayer.myShape.setTexture(&myPlayerWalkDownStrip);
		}
		if (myPlayer.myAnimationState == myPlayer.WalkLeft)
		{
			myPlayerLeftAnimation.Update(0, myDeltaTime);
			myPlayer.myShape.setTextureRect(myPlayerLeftAnimation.myUvRect);
			myPlayer.myShape.setTexture(&myPlayerWalkLeftStrip);
		}
		if (myPlayer.myAnimationState == myPlayer.WalkRight)
		{
			myPlayerRightAnimation.Update(0, myDeltaTime);
			myPlayer.myShape.setTextureRect(myPlayerRightAnimation.myUvRect);
			myPlayer.myShape.setTexture(&myPlayerWalkRightStrip);
		}
		if (myPlayer.myAnimationState == myPlayer.WalkUp)
		{
			myPlayerUpAnimation.Update(0, myDeltaTime);
			myPlayer.myShape.setTextureRect(myPlayerUpAnimation.myUvRect);
			myPlayer.myShape.setTexture(&myPlayerWalkUpStrip);
		}
		if (myPlayer.myAnimationState == myPlayer.Idle)
		{
			myPlayerDownAnimation.myCurrentImage.x = 2;
			myPlayer.myShape.setTextureRect(myPlayerDownAnimation.myUvRect);
			myPlayerLeftAnimation.myCurrentImage.x = 2;
			myPlayer.myShape.setTextureRect(myPlayerLeftAnimation.myUvRect);
			myPlayerRightAnimation.myCurrentImage.x = 1;
			myPlayer.myShape.setTextureRect(myPlayerRightAnimation.myUvRect);
			myPlayerUpAnimation.myCurrentImage.x = 1;
			myPlayer.myShape.setTextureRect(myPlayerUpAnimation.myUvRect);
		}
		window.draw(myPlayer.myShape);
		//Bat
		if (myEnemy->myAnimationState == myEnemy->Death)
		{
			myBatDeathAnimation.Update(0, myDeltaTime);
			myEnemy->myShape.setTextureRect(myBatDeathAnimation.myUvRect);
			myEnemy->myShape.setTexture(&myBatDeathStrip);
		}
		if (myEnemy->myAnimationState == myEnemy->Fly)
		{
			myBatFlyingAnimation.Update(0, myDeltaTime);
			myEnemy->myShape.setTextureRect(myBatFlyingAnimation.myUvRect);
			myEnemy->myShape.setTexture(&myBatFlyingStrip);
		}
		if (myEnemy->myAnimationState == myEnemy->Attack)
		{
			myBatAttackAnimation.Update(0, myDeltaTime);
			myEnemy->myShape.setTextureRect(myBatAttackAnimation.myUvRect);
			myEnemy->myShape.setTexture(&myBatAttackStrip);
		}
		//HealthUI
		window.draw(myHealthUI.myHealthUIShape);
		myHealthUI.Update(&myPlayer);
		window.draw(myHealthUI.myHealthBar);
		window.draw(myHealthUI.myManaBar);

		//collision
		for (size_t i = myPlayer.myBulletVector.size(); i > 0; i--)
		{
			if (myPlayer.myBulletVector[i - 1]->myShape.getGlobalBounds().intersects(myEnemy->myShape.getGlobalBounds()))
			{
				window.draw(myHit);
			}
		}
		if (myPlayer.myShape.getGlobalBounds().intersects(myEnemy->myShape.getGlobalBounds()))
		{
			window.draw(myHit);
		}

		//Keybinds	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && !pressed)
		{
			myPlayer.SetHealth(myPlayer.GetHealth() - 1);
			pressed = true;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::G) && pressed)
		{
			pressed = false;
		}
		sf::Vector2f tempMousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		//Player Update 
		myPlayer.Update(tempMousePosition);
		window.display();
		//Bat Update
		myEnemy->Update(&myPlayer);

		//Kill bullets outside of screen
		for (size_t i = myPlayer.myBulletVector.size(); i > 0; i--)
		{
			if (myPlayer.myBulletVector[i - 1]->myShape.getPosition().x < 0)
			{
				delete myPlayer.myBulletVector[i - 1];
				myPlayer.myBulletVector[i - 1] = NULL;
				myPlayer.myBulletVector.erase(myPlayer.myBulletVector.begin() + i - 1);
			}
		}
	}
}
