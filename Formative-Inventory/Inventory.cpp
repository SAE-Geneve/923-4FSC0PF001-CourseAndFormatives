#include "Inventory.h"

#include <iostream>



void Inventory::Add(Item itemToAdd)
{
	ItemsStorage.emplace_back(itemToAdd);
}

Item Inventory::Equip(int number)
{
	// Attention aux numéros qui marchent pas


	return ItemsStorage[number];

	

}

void Inventory::Display()
{
	int idx = 0;
	for(auto oneItem : ItemsStorage)
	{
		std::cout << idx << ":" << oneItem.getName() << std::endl;
		idx++;
	}

}

