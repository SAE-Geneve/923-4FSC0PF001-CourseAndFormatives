#include "Monster.h"

Monster::Monster(int health) : Health(health)
{
	
}

std::string Monster::ToString()
{
	return std::to_string(Health) + " hp";
}

void Monster::TakeDamage()
{

}

void Monster::Attack(Monster& ennemy)
{

	if(ATK - ennemy.DEF > 0)
	{
		ennemy.TakeDamage();
	}

}

