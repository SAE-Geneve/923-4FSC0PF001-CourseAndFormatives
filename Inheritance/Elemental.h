#pragma once
#include <string>

class Elemental
{
	std::string Element;
	int ElementalPower;

public:
	Elemental(std::string element, int elementalPower);
	std::string ToString();

};

