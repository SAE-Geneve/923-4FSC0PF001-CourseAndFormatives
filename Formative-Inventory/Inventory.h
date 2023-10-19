#pragma once

#include "Item.h"
#include <vector>

class Inventory
{

	std::vector<Item*> ItemsStorage;

public:
	void Add(Item& itemToAdd);
	Item* UseOne(unsigned int number);

	void Display();

};



