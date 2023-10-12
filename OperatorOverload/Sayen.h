#pragma once
#include <string>

class Sayen
{
public:
	std::string name;
	int power;

	Sayen operator+(Sayen& sayen);

	bool operator>=(Sayen& sayen);
	bool operator==(Sayen& sayen);

};

