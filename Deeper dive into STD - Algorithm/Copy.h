#pragma once

#include <algorithm>
#include <vector>

#include "Display.h"
#include "Person.h"

using namespace std;

void copyNumbers(vector<int>& numbers)
{
	vector<int> nToCopy = { 1,2,3,4,5 };

	displayNumbers(numbers);

	// Copy a bunch of int
	std::copy(
		nToCopy.begin(),			// Copied interval start
		nToCopy.end(),				// Copied interval end
		numbers.begin() + 2);	// Copy position in to destination
	displayNumbers(numbers);

	// copy and add a bunch if int respecting conditions
	int condition = 3;
	std::copy_if(
		nToCopy.begin(),										// Copied interval start
		nToCopy.end(),											// Copied interval end
		numbers.begin(),										// Copy position in to destination
		[condition](auto n) {return n >= condition; }			// Condition to respect to be copied
	);	
	displayNumbers(numbers);

	// Insert at the end a bunch of int
	std::copy(
		nToCopy.begin(),								// Inserted interval start
		nToCopy.end(),									// Inserted interval end
		std::back_inserter(numbers)					// Call to back inserter to do the insertion
	);
	displayNumbers(numbers);

}

bool ageCriteria(Person p)
{
	return p.getAge() <= 75;
}

class ageCriteriaClass
{
	int _ageToCompare;

public:

	ageCriteriaClass(int ageToCompare) : _ageToCompare(ageToCompare)
	{
		
	}
	bool operator()(Person p) {
		return p.getAge() <= _ageToCompare;
	}

	bool operator()(int n)
	{
		return n >= _ageToCompare;
	}
};

void copyPersons(std::vector<Person>& persons)
{

	// Copy some new person in the vector
	vector<Person> newPersons;
	newPersons.push_back(Person("Gandhi", "Indhirah", 72));
	newPersons.push_back(Person("Berlusconi", "Silvio", 86));

	// Copy into the GLOBAL vector
	//std::copy(
	//	newPersons.begin(),
	//	newPersons.end(),
	//	std::back_inserter(persons)
	//);
	//displayEverybody(newPersons);

	float ageLimit = 75;

	ageCriteriaClass ageCriteriaObject(75);

	// Copy the person only if their age is less than the limit
	std::copy_if(
		newPersons.begin(),
		newPersons.end(),
		std::back_inserter(persons),
		ageCriteriaObject
	);
	displayEverybody(persons);
}



