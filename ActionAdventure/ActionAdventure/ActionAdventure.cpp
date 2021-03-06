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
	std::vector<Animation*> myBatAnimationAttackVector;
	std::vector<Animation*> myBatAnimationFlyingVector;
	std::vector<Animation*> myBatAnimationDeathVector;
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
	//Bat animation & creation
	Enemy* myEnemy;
	myEnemy = new Enemy(0.00015f, 100, 100);
	myEnemy->myShape.setTexture(&myBatFlyingStrip);
	myBatVector.push_back(myEnemy);
	Animation* myBatAttackAnimation;
	myBatAttackAnimation = new Animation(&myBatAttackStrip, sf::Vector2u(5, 1), 0.1f);
	myBatAnimationAttackVector.push_back(myBatAttackAnimation);
	Animation* myBatFlyingAnimation;
	myBatFlyingAnimation = new Animation(&myBatFlyingStrip, sf::Vector2u(5, 1), 0.1f);
	myBatAnimationFlyingVector.push_back(myBatFlyingAnimation);
	Animation* myBatDeathAnimation;
	myBatDeathAnimation = new Animation(&myBatDeathStrip, sf::Vector2u(5, 1), 0.1f);
	myBatAnimationDeathVector.push_back(myBatDeathAnimation);

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
		#pragma region Drawing 
		//Player
		window.draw(myPlayer.myShape);
		//Bat
		for (size_t i = myBatVector.size(); i > 0; i--)
		{
			window.draw(myBatVector[i - 1]->myShape);
		}
		//Bullet
		for (size_t i = myPlayer.myBulletVector.size(); i > 0; i--)
		{
			window.draw(myPlayer.myBulletVector[i - 1]->myShape);
			myPlayer.myBulletVector[i - 1]->Update();
		}
		//HealthUI
		window.draw(myHealthUI.myHealthUIShape);
		window.draw(myHealthUI.myHealthBar);
		window.draw(myHealthUI.myManaBar);
#pragma endregion
		window.display();
		#pragma region Collison
		//Bat collision with player
		for (size_t i = myBatVector.size(); i > 0; i--)
		{
			if (myPlayer.myShape.getGlobalBounds().intersects(myBatVector[i - 1]->myShape.getGlobalBounds()))
			{
				delete myBatVector[i - 1];
				myBatVector[i - 1] = NULL;
				myBatVector.erase(myBatVector.begin() + i - 1);
				delete myBatAnimationFlyingVector[i - 1];
				myBatAnimationFlyingVector[i - 1] = NULL;
				myBatAnimationFlyingVector.erase(myBatAnimationFlyingVector.begin() + i - 1);
				delete myBatAnimationAttackVector[i - 1];
				myBatAnimationAttackVector[i - 1] = NULL;
				myBatAnimationAttackVector.erase(myBatAnimationAttackVector.begin() + i - 1);
				delete myBatAnimationDeathVector[i - 1];
				myBatAnimationDeathVector[i - 1] = NULL;
				myBatAnimationDeathVector.erase(myBatAnimationDeathVector.begin() + i - 1);
			}
		}
		//Bullet collision with bat
		for (size_t i = myPlayer.myBulletVector.size(); i > 0; i--)
		{
			for (size_t x = myBatVector.size(); x > 0; x--)
			{
				if (myPlayer.myBulletVector[i - 1]->myShape.getGlobalBounds().intersects(myBatVector[x - 1]->myShape.getGlobalBounds()))
				{
					delete myBatVector[x - 1];
					myBatVector[x - 1] = NULL;
					myBatVector.erase(myBatVector.begin() + x - 1);
					delete myBatAnimationFlyingVector[x - 1];
					myBatAnimationFlyingVector[x - 1] = NULL;
					myBatAnimationFlyingVector.erase(myBatAnimationFlyingVector.begin() + x - 1);
					delete myBatAnimationAttackVector[x - 1];
					myBatAnimationAttackVector[x - 1] = NULL;
					myBatAnimationAttackVector.erase(myBatAnimationAttackVector.begin() + x - 1);
					delete myBatAnimationDeathVector[x - 1];
					myBatAnimationDeathVector[x - 1] = NULL;
					myBatAnimationDeathVector.erase(myBatAnimationDeathVector.begin() + x - 1);
				}
			}
		}
#pragma endregion

		#pragma region Keybinds
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
#pragma endregion

		#pragma region Updates
		//Player Update 
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
		myPlayer.Update(tempMousePosition);
		//Bat Update
		for (size_t i = myBatAnimationDeathVector.size(); i > 0; i--)
		{
			if (myBatVector[i - 1]->myAnimationState == myBatVector[i - 1]->Death)
			{
				myBatAnimationDeathVector[i - 1]->Update(0, myDeltaTime);
				myBatVector[i - 1]->myShape.setTextureRect(myBatAnimationDeathVector[i - 1]->myUvRect);
				myBatVector[i - 1]->myShape.setTexture(&myBatDeathStrip);
			}
		}
		for (size_t i = myBatAnimationFlyingVector.size(); i > 0; i--)
		{
			if (myBatVector[i - 1]->myAnimationState == myBatVector[i - 1]->Fly)
			{
				myBatAnimationFlyingVector[i - 1]->Update(0, myDeltaTime);
				myBatVector[i - 1]->myShape.setTextureRect(myBatAnimationFlyingVector[i - 1]->myUvRect);
				myBatVector[i - 1]->myShape.setTexture(&myBatFlyingStrip);
			}
		}
		for (size_t i = myBatAnimationAttackVector.size(); i > 0; i--)
		{
			if (myBatVector[i - 1]->myAnimationState == myBatVector[i - 1]->Attack)
			{
				myBatAnimationAttackVector[i - 1]->Update(0, myDeltaTime);
				myBatVector[i - 1]->myShape.setTextureRect(myBatAnimationAttackVector[i - 1]->myUvRect);
				myBatVector[i - 1]->myShape.setTexture(&myBatAttackStrip);
			}
		}
		for (size_t i = myBatVector.size(); i > 0; i--)
		{
			myBatVector[i - 1]->Update(&myPlayer);
		}
		//HealthUI Update
		myHealthUI.Update(&myPlayer);
#pragma endregion


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
