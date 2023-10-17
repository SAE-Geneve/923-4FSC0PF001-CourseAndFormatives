#pragma once
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "Display.h"

#pragma region Numbers
void ascendingSortNumbers(std::vector<int>& numbers)
{

	// Simple as hell, int are naturally sortable
	std::sort(numbers.begin(), numbers.end());

	std::cout << "After ascending sorting" << std::endl;
	displayNumbers(numbers);

}

void descendingSortNumbers(std::vector<int>& numbers)
{
	// Simple as hell, int are naturally sortable
	// Precise as 3rd parameter the criteria to sort them
	std::sort(numbers.begin(), numbers.end(), greater<int>());

	std::cout << "After descending sorting" << std::endl;
	displayNumbers(numbers);

}

void randomShuffleNumbers(std::vector<int>& numbers)
{
	// Simple as hell, int are naturally sortable
	std::random_shuffle(numbers.begin(), numbers.end());

	std::cout << "After random shuffle" << std::endl;
	displayNumbers(numbers);

}

#pragma endregion

#pragma region Persons (Or objects)
void sortPersons_Lambda(vector<Person>& persons)
{

	// Objects are not that simple,
	// you have to determinate the sorting criteria by yourself
	// First way : lambda as ascending order
	std::sort(
		persons.begin(),
		persons.end(),
		[](Person& p, Person& q)
		{
			return p.getAge() < q.getAge();
		}
	);

	std::cout << "After ascending sorting (Lambda)" << std::endl;
	displayEverybody(persons);

}

// THIS IS NOT THE GOOD PLACE
// To sort object (not naturally sortable), you can overload the comparison operator
//bool Person::operator<(Person& p)
//{
//	return this->age_ < p.age_;
//}

void sortPersons_Operator(vector<Person>& persons)
{

	// Objects are not that simple,
	// you have to determinate the sorting criteria by yourself
	// Second way : class operator overloaded
	std::sort(
		persons.begin(),
		persons.end()
	);

	std::cout << "After ascending sorting (Operator)" << std::endl;
	displayEverybody(persons);

}

bool compPerson(Person& p, Person& q)
{
	return p.getAge() < q.getAge();
}
void sortPersons_Functor(vector<Person>& persons)
{

	// Objects are not that simple,
	// you have to determinate the sorting criteria by yourself
	// Third way : functor making the comparison for you
	std::sort(
		persons.begin(),
		persons.end(),
		compPerson
	);

	std::cout << "After ascending sorting (Functor)" << std::endl;
	displayEverybody(persons);

}

void shufflePersons(vector<Person>& persons)
{

	std::random_shuffle(persons.begin(), persons.end());

	std::cout << "After shuffle" << std::endl;
	displayEverybody(persons);

}
#pragma endregion
