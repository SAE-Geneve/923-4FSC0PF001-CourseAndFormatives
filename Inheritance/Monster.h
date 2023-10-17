#pragma once
#include <string>

class Monster
{

protected:
	int Health;
	int ATK, DEF;

protected:
	Monster(int health);

	std::string ToString();

	void TakeDamage();
	void Attack(Monster& ennemy);

};

