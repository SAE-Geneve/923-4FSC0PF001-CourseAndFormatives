// Strings.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

std::string name;
std::string surname;
int age;
std::string status;

int main()
{
	std::cout << "Bonjour, quel est ton prenom" << std::endl;
	std::cin >> name;

	std::cout << "et ton nom" << std::endl;
	std::cin >> surname;

	std::cout << "J'aimerais aussi savoir ton age" << std::endl;
	std::cin >> age;

	if (age < 25)
		status = "jeune";
	else
		status = "vieux";

	std::cout << "Bienvenu dans mon programe " << surname << " " << name << " tu as " << age << " donc tu es " << status << " mais c'est pas pour etre mechant.";

}

