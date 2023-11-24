#include <iostream>
#include <vector>

#include "Entity.h"

int main()
{
	// ------------------------------------------------------------------------
	std::cout << "ADD ------------------------------------------------\n";
	std::vector<Entity> entities;

	Entity entity_to_add("Linus", 2);/*
	entity_to_add.name_ = "Linus";
	entity_to_add.value_ = 2;*/
	entities.push_back(entity_to_add);

	entities.push_back(Entity());
	entities.back().name_ = "Anthony";

	entities.emplace_back();
	entities.back().name_ = "Maxence";
	entities.back().value_ = 2;

	entities.emplace_back("Sebastien", 3);
	entities.back().value_ = 4;

	std::cout << entities.size() << std::endl;
	for (Entity& local_entity : entities)
	{
		std::cout << local_entity.name_ << ":" << local_entity.value_ << std::endl;
	}

	// Remove ----------------------------------------------------------------------------
	std::cout << "REMOVE ------------------------------------------------\n";
	std::vector<Entity>::iterator it = entities.begin();

	int valueToRemove = 2;
	it = std::remove_if(
		entities.begin(),
		entities.end(),
		[valueToRemove](Entity e)
		{
			std::cout << "lambda:" << e.name_ << std::endl;
			return e.value_ == valueToRemove;
		}
	);
	entities.erase(it, entities.end());

	std::cout << entities.size() << std::endl;
	for (Entity& local_entity : entities)
	{
		std::cout << local_entity.name_ << ":" << local_entity.value_ << std::endl;
	}
}


