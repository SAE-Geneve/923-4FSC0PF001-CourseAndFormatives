#pragma once
#include <string>

class Item
{

protected:
	std::string Name;

public:
	Item(std::string name) : Name(name) {}

	virtual void Use() = 0;
	virtual std::string ToString() = 0;

};

