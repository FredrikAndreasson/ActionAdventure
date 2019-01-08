#ifndef ENEMY_HEADER
#define ENEMY_HEADER
#include <SFML/Graphics.hpp>
class Enemy
{
public:
	Enemy();
	~Enemy();

	sf::RectangleShape myShape;
};
#endif