// EnumExample.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Status.h"

int main()
{
	Status myStatus;
	myStatus = Status::Acidified;
	std::cout << "Statut joueur = ";
	DisplayStatus(myStatus);

	Status monsterStatus;
	monsterStatus = Status::None;
	std::cout << "Statut monstre = ";

	if(monsterStatus != Status::None)
	{
		DisplayStatus(monsterStatus);
	}

}
