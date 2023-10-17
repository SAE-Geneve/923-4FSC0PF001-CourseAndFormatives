#pragma once
#include "Monster.h"

class Fight
{

public:
	static void Combat(Monster& attacker, Monster& defender);
	static float RNG();
};

