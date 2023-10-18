#pragma once
#include <string>

class Item
{

	std::string Name;

public:
	Item(std::string name) : Name(name) {}

	void Use();
	std::string getName() { return Name; }

};

