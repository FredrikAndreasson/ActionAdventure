#include "stdafx.h"
#include "Animation.h"


Animation::Animation(sf::Texture* aTexture, sf::Vector2u anImageCount, float someSwitchTime)
{
	this->myImageCount = anImageCount;
	this->mySwitchTime = someSwitchTime;
	myTotalTime = 0.0f;
	myCurrentImage.x = 0;

	myUvRect.width = aTexture->getSize().x / float(myImageCount.x);
	myUvRect.height = aTexture->getSize().y / float(myImageCount.y);
}


Animation::~Animation()
{
}

void Animation::Update(int aRow, float someDeltaTime, Player* aPlayer)
{
	//what direction is Player going in?
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myImageLow = 16;
		myImageHigh = 24;
		if (myCurrentImage.x > myImageHigh || myCurrentImage.x < myImageLow)
		{
			myCurrentImage.x = myImageLow;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myImageLow = 8;
		myImageHigh = 16;
		if (myCurrentImage.x > myImageHigh || myCurrentImage.x < myImageLow)
		{
			myCurrentImage.x = myImageLow;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myImageLow = 24;
		myImageHigh = 32;
		if (myCurrentImage.x > myImageHigh || myCurrentImage.x < myImageLow)
		{
			myCurrentImage.x = myImageLow;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myImageLow = 0;
		myImageHigh = 8;
		if (myCurrentImage.x > myImageHigh || myCurrentImage.x < myImageLow)
		{
			myCurrentImage.x = myImageLow;
		}
	}



	myCurrentImage.y = aRow;
	myTotalTime += someDeltaTime;
	if (myTotalTime >= mySwitchTime)
	{
		myTotalTime -= mySwitchTime;
		myCurrentImage.x++;

		if (myCurrentImage.x >= myImageHigh)
		{
			myCurrentImage.x = myImageLow;
		}
	}

	myUvRect.left = myCurrentImage.x * myUvRect.width;
	myUvRect.top = myCurrentImage.y * myUvRect.height;
}