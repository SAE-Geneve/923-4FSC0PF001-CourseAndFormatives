#include "Weapon.h"

#include <iostream>

void Weapon::Use()
{
	std::cout << "[Weapon] use of " << Name << std::endl;
}

std::string Weapon::ToString()
{
	return Name + " " + "DPS=" + std::to_string(Dps);
}


