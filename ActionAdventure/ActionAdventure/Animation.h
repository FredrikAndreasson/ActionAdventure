#ifndef ANIMATION_HEADER
#define ANIMATION_HEADER
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* aTexture, sf::Vector2u anImageCount, float someSwitchTime, int aDivisionAmount);
	~Animation();

	void Update(int aRow, float someDeltaTime);

	sf::IntRect myUvRect;
private:
	sf::Vector2u myImageCount;
	sf::Vector2u myCurrentImage;

	float myTotalTime;
	float mySwitchTime;
	int myDivisionAmount;

};
#endif