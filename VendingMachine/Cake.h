#pragma once
#include <string>

class Cake
{
	std::string Flavour;
	static int CakeCount;

public:
	std::string GetFlavour() { return Flavour; }
	void ResetCount();

	Cake(std::string flavour);

	static int HowManyCakes();

};

