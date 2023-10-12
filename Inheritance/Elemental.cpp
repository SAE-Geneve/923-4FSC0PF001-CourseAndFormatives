#include "Elemental.h"

Elemental::Elemental(std::string element, int elementalPower) :
	Element(element),
	ElementalPower(elementalPower)
{
}

std::string Elemental::ToString()
{
	return "Element=" + Element + "(" + std::to_string(ElementalPower) + ")";
}
