#ifndef HEALTHUI_HEADER
#define HEALTHUI_HEADER
#include <SFML/Graphics.hpp>
#include "Player.h"
class HealthUI
{
public:
	HealthUI();
	~HealthUI();

	void Update(Player* aPlayer);

	sf::RectangleShape myHealthUIShape;
	sf::RectangleShape myHealthBar;
	sf::RectangleShape myManaBar;
private:
	//Mana
	float myInitialHealthWidth;
	float myInitialHealthHeight;

	//Mana
	float myInitialManaWidth;
	float myInitialManaHeight;
};
#endif