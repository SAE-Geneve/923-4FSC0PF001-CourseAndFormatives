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

	void Use() override;
	std::string ToString() override;

	Weapon Equip();

};


class Potion : public Item
{

	int Dps;

public:

	Potion(std::string name, int dps) : Item(name)
	{
		Dps = dps;
	};

	void Use() override;
	std::string ToString() override;

	void Drink();

};


