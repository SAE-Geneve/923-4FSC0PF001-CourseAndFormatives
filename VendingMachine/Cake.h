#pragma once
#include <string>

class Cake
{
	std::string Flavour;

public:
	std::string GetFlavour() { return Flavour; }
	Cake(std::string flavour);

};

