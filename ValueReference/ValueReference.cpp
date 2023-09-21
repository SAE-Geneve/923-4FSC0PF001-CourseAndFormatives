// ValueReference.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

int ResetVariable()
{
	return 12243;
}

int main()
{
	int firstVariable = 26;

	std::cout << "Value ? " << firstVariable << std::endl;

	firstVariable = ResetVariable();

	std::cout << "Value ? " << firstVariable << std::endl;

}
