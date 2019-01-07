#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER
#include <SFML/Graphics.hpp>
#include "Player.h"
class Animation
{
public:
	Animation(sf::Texture* aTexture, sf::Vector2u anImageCount, float someSwitchTime);
	~Animation();

	void Update(int aRow, float someDeltaTime, Player* aPlayer);

	sf::IntRect myUvRect;
private:
	sf::Vector2u myImageCount;
	sf::Vector2u myCurrentImage;

	float myTotalTime;
	float mySwitchTime;
	int myImageLow;
	int myImageHigh;
	int myLastX;
	int myLastY;

};
#endif