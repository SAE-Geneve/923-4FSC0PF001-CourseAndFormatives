// Polymorphism.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Animal.h"

void KickAnimal(Animal& animal)
{
	animal.Shout();
}

int main()
{


	Cat felix;
	Dog paf;

	//Animal animal;
	//animal = felix;
	//animal.Purr();

	KickAnimal(felix);
	KickAnimal(paf);


}

