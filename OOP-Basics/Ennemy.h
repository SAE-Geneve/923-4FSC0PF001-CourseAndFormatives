#pragma once
#include <string>

#include "Weapon.h"

class Ennemy {

	int hit_points = 10;

public:
	std::string name;
	
	int defenseValue = 1;
	int attackValue = 1;

	Weapon weapon;

	void Heal();
	void Heal(int healValue);
	void Heal(int healValue, float debuff);

	void TakeDamage(int attackPoints);

	Ennemy();
	Ennemy(std::string _name, int _hp, int _att, int _def);
	Ennemy(std::string _name);

}; //

