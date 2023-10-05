#pragma once
#include <string>
#include <vector>

#include "Cake.h"

class VendingMachine
{
	std::string Location;
	int Money; // Currency = CHF
	//int NbCakes;
	int NbCans;

	std::vector<Cake> Cakes;

public:
	VendingMachine(std::string location, int money, int nbCans);
	VendingMachine(int money, int nbCans);
	~VendingMachine();

	void Display();

	int GetNbCakes() { return Cakes.size(); }

	void RefillCakes(int nbCakes, std::string flavour);
	void TakeCakes(int nbCakes, std::string flavour);

};

