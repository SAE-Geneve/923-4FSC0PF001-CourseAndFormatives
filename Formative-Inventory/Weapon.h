#pragma once
#include "Item.h"

class Weapon : public Item
{

	int Dps;

public:

	Weapon(std::string name, int dps) : Item(name)
	{
		Dps = dps;
	};

	void Equip();

};

