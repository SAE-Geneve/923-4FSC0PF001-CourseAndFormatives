#pragma once
#include "Elemental.h"
#include "Monster.h"

class Troll : public Monster, public Elemental
{

public:
	Troll(std::string element, int elementalPower);


	std::string ToString();

	int GetHealth() { return Health; };
	void SetHealth(int health) { Health = health; };

};

