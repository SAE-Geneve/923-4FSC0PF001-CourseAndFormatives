#include "Cake.h"

int Cake::CakeCount = 0;

int Cake::HowManyCakes()
{
	return CakeCount;
}

Cake::Cake(std::string flavour) : Flavour(flavour)
{
	CakeCount++;
}


void Cake::ResetCount()
{
	CakeCount = 0;
}