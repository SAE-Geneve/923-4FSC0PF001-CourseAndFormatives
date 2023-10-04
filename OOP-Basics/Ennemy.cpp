#include "Ennemy.h"

#include <iostream>
#include "Ennemy.h"

Ennemy::Ennemy()
{
	
}


Ennemy::Ennemy(std::string _name)
{
	std::cout << "Constructor is called" << std::endl;
	name = _name;
}

Ennemy::Ennemy(std::string _name, int _hp, int _att, int _def)
{
	name = _name;
	hit_points = _hp;
	attackValue = _att;
	defenseValue = _def;
}



void Ennemy::Heal()
{
	std::cout << "Basic Heal" << std::endl;
	hit_points += 3;
}
void Ennemy::Heal(int healValue)
{
	std::cout << "Special Heal : " << healValue << std::endl;
	hit_points += healValue;
}
void Ennemy::Heal(int healValue, float debuff)
{
	std::cout << "Special Heal : " << healValue << std::endl;
	hit_points += (healValue - debuff);
}

void Ennemy::TakeDamage(int attackPoints)
{
	if(attackPoints > defenseValue)
	{
		hit_points = hit_points - attackPoints;
	}
}


