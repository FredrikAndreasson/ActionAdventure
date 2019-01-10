#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER
#include <SFML/Graphics.hpp>
#include "Player.h"
class Animation
{
public:
	Animation(sf::Texture* aTexture, sf::Vector2u anImageCount, float someSwitchTime);
	~Animation();

	void Update(int aRow, float someDeltaTime);

	sf::IntRect myUvRect;
	sf::Vector2u myCurrentImage;
private:
	sf::Vector2u myImageCount;

	float myTotalTime;
	float mySwitchTime;

};
#endif