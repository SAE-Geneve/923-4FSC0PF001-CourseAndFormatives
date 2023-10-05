#include "VendingMachine.h"

#include <iostream>

VendingMachine::VendingMachine(std::string location, int money, int nbCans) : Location(location), Money(money), NbCans(nbCans)
{

}

VendingMachine::VendingMachine(int money, int nbCans)
{
	this->Location = "Storage";

	this->Money = money;
	this->NbCans = nbCans;

}

VendingMachine::~VendingMachine()
{
	std::cout << "This machine is dead" << std::endl;
}

void VendingMachine::Display()
{
	std::cout << std::endl << "Location :" << this->Location << std::endl;

	std::cout << "Content of the machine :" << std::endl;
	std::cout << Cakes.size() << " Cakes" << std::endl;
	for (int n = 0; n < Cakes.size(); ++n)
	{
		std::cout << Cakes[n].GetFlavour() << ";";
	}
	std::cout << std::endl;

	std::cout << NbCans << " Cans" << std::endl;
	std::cout << Money << " CHF" << std::endl;
}

void VendingMachine::RefillCakes(int nbCakes, std::string flavour) {
	if (nbCakes > 0)
	{
		for (int n = 0; n < nbCakes; n++)
		{
			// Option 1
			//Cake genericCake(flavour);
			//Cakes.push_back(genericCake);
			// Option 2 : la mieux
			Cakes.emplace_back(flavour);
		}
	}
}

void VendingMachine::TakeCakes(int nbCakes, std::string flavour)
{

	int nbCakesDeleted = 0;

	for (std::vector<Cake>::iterator cake = Cakes.begin(); cake < Cakes.end();)
	{
		if(nbCakesDeleted >= nbCakes)
		{
			return;
		}

		if (flavour == cake->GetFlavour())
		{
			cake = Cakes.erase(cake);
			nbCakesDeleted++;
			//break;
		}
		else
		{
			cake++;
		}
	}
}

