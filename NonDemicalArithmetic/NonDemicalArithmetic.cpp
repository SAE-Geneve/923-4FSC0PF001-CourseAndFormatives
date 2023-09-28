// NonDemicalArithmetic.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

int main()
{

	// Increment ------------------------------------------------
	int a = 0;

	int b = a++;
	int c = ++a;

	for (int a = 0; a <= 10; ++a)
	{
		std::cout << a << std::endl;
	}
	std::cout << a << std::endl;

	// Roll right / left
	std::cout << "roll " << std::endl;
	////// a = 5(00000101), b = 9(00001001)
	////unsigned char d = 5, e = 9;

	////// The result is 00001010
	////printf("d<<1 = %d\n", (d << 1));

	////// The result is 00010010
	////printf("e<<1 = %d", (e << 1));
	////return 0;
	int d = 4;

	d = (d >> 1);
	std::cout << d << std::endl;

	d = (d << 2);
	std::cout << d << std::endl;


}

