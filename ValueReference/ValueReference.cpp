// ValueReference.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>


void Input(int& x, int& y)
{

}

void ResetVariable(int& variable)
{
	variable = 0;
}

int main()
{
	int firstVariable = 26;

	std::cout << "Value ? " << firstVariable << std::endl;

	ResetVariable(firstVariable);

	std::cout << "Value ? " << firstVariable << std::endl;

}
