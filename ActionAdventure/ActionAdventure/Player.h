#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <SFML/Graphics.hpp>
class Player
{
	enum mySpells{Fireball, Whirlwind, Heal, Sprint, Frostbreath, Firetotem};
public:
	Player(int someHealth, int someDamage, int someSpellPower, int someMana, int someManaRegen, int someLives);
	~Player();

	sf::RectangleShape myShape;
	sf::RectangleShape myHealthUIShape;

	void Update();

	//Getters
	float GetHealth();
	float GetMana();
	float GetManaRegen();
	int GetSpellPower();
	int GetDamage();
	int GetLives();

	//Setters
	void SetHealth(float aValue);
	void SetMana(float aValue);
	void SetManaRegen(float aValue);
	void SetSpellPower(int aValue);
	void SetDamage(int aValue);
	void SetLives(int aValue);
private:
	//Stats
	float myHealth;
	float myMana;
	float myManaRegen;
	int myDamage;
	int mySpellPower;
	int myLives;

	//Items & spells
	mySpells mySpellBook[6];
	std::string myHotbar[5];
	std::string myArmor[4];
	std::string myInventory[12];
};
#endif