// Arrays.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <array>
#include <iostream>

int main()
{

	// Old school ------------------------------------------------------------
	//int numbers[6]
	//{
	//	12, 34, 56, 3, 6, 7
	//};
	//for (int index = 0; index < 8; index++)
	//{
	//	std::cout << "bulletin de loto " << numbers[index] << std::endl;
	//}
	//std::cout << "--------------------------------------------" << std::endl;

	// medium school -------------------------------------------------------------
	std::array<int, 7> mediumSchoolNumbers;
	for(int& newNumber : mediumSchoolNumbers)
	{
		newNumber = rand();
	}

	for (int index = 0; index < mediumSchoolNumbers.size(); index++)
	{
		std::cout << "bulletin de loto " << mediumSchoolNumbers[index] << std::endl;
	}

	for (int number : mediumSchoolNumbers)
	{
		std::cout << "bulletin de loto " << number << std::endl;
	}

	return EXIT_SUCCESS;

}

