// Strings - Exercices - 2 - SeekForVowels.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <string>

int main()
{

	std::string word;

	const std::string vowels = "aeiouy";
	int nbVowels = 0;

	const std::string digits = "0123456789";
	int nbDigits = 0;

	std::cout << "Please, input a string" << std::endl;
	std::getline(std::cin, word);
	
	for (char c : word)
	{
		
		if (vowels.find(tolower(c)) != std::string::npos)
		{
			nbVowels++;
		}

		if (digits.find(tolower(c)) != std::string::npos)
		{
			nbDigits++;
		}

	}

	std::cout << "There is " << nbVowels << " vowels in " << word << std::endl;
	std::cout << "There is " << nbDigits << " digits in " << word << std::endl;

}

