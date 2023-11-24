#include "Entity.h"

Entity::Entity()
{
	name_ = "no_name";
	value_ = -1;
}

Entity::Entity(std::string name, int value) : name_(name), value_(value)
{
	//name_ = name;
	//value_ = value;
}


