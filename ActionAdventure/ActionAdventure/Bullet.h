#ifndef BULLET_HEADER
#define BULLET_HEADER
#include <SFML/Graphics.hpp>
class Bullet
{
public:
	Bullet();
	~Bullet();
	void Init(float anX, float aY, sf::RectangleShape aRectangle);
	void Update();

	sf::RectangleShape myShape;
};
#endif