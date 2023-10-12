#include "Troll.h"

Troll::Troll(std::string element, int elementalPower) :
	Monster(75),
	Elemental(element, elementalPower)
{
}

std::string Troll::ToString()
{
	return Monster::ToString() + " " + Elemental::ToString();
}

