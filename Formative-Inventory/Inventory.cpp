#include "Inventory.h"

#include <iostream>

#include "Weapon.h"


void Inventory::Add(Item& itemToAdd)
{
	ItemsStorage.emplace_back(&itemToAdd);
}

Item* Inventory::UseOne(unsigned int number)
{
	// Attention aux numéros qui marchent pas
	if (number > 0 && number < ItemsStorage.size())
	{
		return ItemsStorage[number];
	}
	else
	{
		return nullptr;
	}
}

void Inventory::Display()
{
	int idx = 0;
	for (auto oneItem : ItemsStorage)
	{
		std::cout << "[" << idx++ << "]" << " - " << oneItem->ToString() << std::endl;
	}

	//for(int i = 0; i > ItemsStorage.size(); i++)
	//{
	//	ItemsStorage[i]->ToString();
	//}

}

