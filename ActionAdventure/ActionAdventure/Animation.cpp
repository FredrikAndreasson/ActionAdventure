#include "stdafx.h"
#include "Animation.h"


Animation::Animation(sf::Texture* aTexture, sf::Vector2u anImageCount, float someSwitchTime, int aDivisionAmount)
{
	this->myImageCount = anImageCount;
	this->mySwitchTime = someSwitchTime;
	this->myDivisionAmount = aDivisionAmount;
	myTotalTime = 0.0f;
	myCurrentImage.x = 0;

	myUvRect.width = aTexture->getSize().x / float(myImageCount.x);
	myUvRect.height = aTexture->getSize().y / float(myImageCount.y);
}


Animation::~Animation()
{
}

void Animation::Update(int aRow, float someDeltaTime)
{
	myCurrentImage.y = aRow;
	myTotalTime += someDeltaTime;
	if (myTotalTime >= mySwitchTime)
	{
		myTotalTime -= mySwitchTime;
		myCurrentImage.x++;

		if (myCurrentImage.x >= myImageCount.x / myDivisionAmount)
		{
			myCurrentImage.x = 0;
		}
	}

	myUvRect.left = myCurrentImage.x * myUvRect.width;
	myUvRect.top = myCurrentImage.y * myUvRect.height;
}