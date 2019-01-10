#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>
class Player
{
	enum Spells{Fireball, Whirlwind, Heal, Sprint, Frostbreath, Firetotem};
public:
	Player(float someHealth, int someDamage, int someSpellPower, float someMana, float someManaRegen, int someLives);
	~Player();

	sf::RectangleShape myShape;

	void Update(sf::Vector2f aMousePosition);
	//Animation state
	enum AnimationState { WalkUp, WalkDown, WalkLeft, WalkRight, Attack, Idle };
	AnimationState myAnimationState;

	//Others
	std::vector<Bullet*> myBulletVector;

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
	float mySpeed;
	float myHealth;
	float myMana;
	float myManaRegen;
	int myDamage;
	int mySpellPower;
	int myLives;
	

	//Items & spells
	Spells mySpellBook[6];
	std::string myHotbar[5];
	std::string myArmor[4];
	std::string myInventory[12];

	//others
	int myFireRate;

};
#endif