#ifndef BULLET_HEADER
#define BULLET_HEADER
#include <SFML/Graphics.hpp>
class Bullet
{
public:
	Bullet(float anX, float aY, sf::RectangleShape aRectangle, float anAngle, float aSpeed);
	~Bullet();
	void Update();

	sf::RectangleShape myShape;

	float myAngle;
	float mySpeed;
};
#endif