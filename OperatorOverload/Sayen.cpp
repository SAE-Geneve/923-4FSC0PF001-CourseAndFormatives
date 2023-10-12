#include "Sayen.h"

Sayen Sayen::operator+(Sayen& sayen)
{
	Sayen fusion;

	fusion.power = this->power + sayen.power;
	fusion.name = this->name;

	return fusion;

}

bool Sayen::operator>=(Sayen& sayen)
{
	return this->power >= sayen.power;
}

bool Sayen::operator==(Sayen& sayen)
{
	return (this->power == sayen.power && this->name == sayen.name);
}


//std::ostream& Sayen::operator<<(std::ostream& os, const Sayen& obj)
//{
//	return os;
//}

//std::ostream& Sayen::operator<<(std::ostream& os, const Sayen& obj)
//{
//	// write obj to stream
//	os << obj.name;
//	return os;
//}
