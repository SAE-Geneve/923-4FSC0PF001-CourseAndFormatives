#pragma once
#include <iostream>

class Animal
{

	std::string name;

public:
	virtual void Shout() = 0;
	std::string GetName() { return name; };
	void ResetName()
	{
		name = "";
	}

};

class Dog : public Animal
{
	void Shout()
	{
		std::cout << "Waf, waf" << std::endl;
	}

	void Fetch()
	{
		
	}
};

class Cat : public Animal
{
	void Shout()
	{
		std::cout << "miaou, miaou" << std::endl;
	}

	void Purr()
	{
		
	}
};



