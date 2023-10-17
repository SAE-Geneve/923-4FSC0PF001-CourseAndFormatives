#pragma once
#include <iostream>
#include <vector>

#include "Display.h"

bool ifRemoveEvenNumbers(int n_) {
	return n_ % 2 == 0;
}

// Arbitrary remove of one iterator
void removeNumbers(std::vector<int>& numbers, const int nToRemove)
{
	auto removeIt = std::remove(numbers.begin(), numbers.end(), nToRemove);
	numbers.erase(removeIt, numbers.end());
	displayNumbers(numbers);

	std::cout << "After " << nToRemove << " remove" << std::endl;
	displayNumbers(numbers);

}

// Search and remove
void removeEvenNumbers(std::vector<int>& numbers)
{
	auto removeIt = std::remove_if(
		numbers.begin(),
		numbers.end(),
		[](int n) {return n % 2;});
	
	numbers.erase(removeIt, numbers.end());
	std::cout << "After removing even numbers" << std::endl;
	displayNumbers(numbers);

}

// Search and remove
void removeIfNamePersons(std::vector<Person>& persons, std::string name)
{
	auto removeIt = std::remove_if(
		persons.begin(),
		persons.end(),
		[name](Person& p) {return p.getName() == name; });
	persons.erase(removeIt, persons.end());

	std::cout << "After removing persons named " << name << std::endl;
	displayEverybody(persons);

}


void removeOldPersons(std::vector<Person>& persons, int ageLimit)
{
	auto removeIt = std::remove_if(
		persons.begin(),
		persons.end(),
		[ageLimit](Person& p) {return p.getAge() > ageLimit; });

	persons.erase(removeIt, persons.end());

	std::cout << "After removing persons older than "  << ageLimit << std::endl;
	displayEverybody(persons);

}
