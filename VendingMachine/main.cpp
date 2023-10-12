// VendingMachine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Cake.h"
#include "VendingMachine.h"

void FillMachines()
{
	VendingMachine filledMachine(4, 5);
	filledMachine.Display();
}

int main()
{

	FillMachines();

	VendingMachine cafet("cafet", 0, 2);
	cafet.RefillCakes(3, "chips");
	cafet.RefillCakes(2, "choco");
	cafet.RefillCakes(3, "chips");
	cafet.Display();

	cafet.TakeCakes(4, "chips");
	cafet.Display();

	VendingMachine teachers("staff room", 200, 25);
	teachers.Display();

	VendingMachine cafet2 = cafet;
	cafet2.Display();

	if (cafet.GetNbCakes() <= 0)
	{
		std::cout << "il y a plus de gateaux !!!!!" << std::endl;
		//cafet.RefillCakes(6);
		//teachers.TakeCakes(6);
	}

	cafet.Display();
	teachers.Display();

	Cake chocolateCake("choco");
	std::cout << chocolateCake.HowManyCakes() << std::endl;

	Cake chipsCake("chips");
	std::cout << chipsCake.HowManyCakes() << std::endl;

	std::cout << Cake::HowManyCakes() << std::endl;

	chipsCake.ResetCount();

	return EXIT_SUCCESS;

}
