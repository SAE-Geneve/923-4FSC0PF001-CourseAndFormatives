#pragma once
#include <string>

enum class ItemType
{
	Potion,
	Bow,
	Sword
};

class item
{
public:
	int force;
	std::string name;
	int type;

	item(int _force, std::string _name, int _type) : force(_force), name(_name), type(_type) {};
	item() {};
};

