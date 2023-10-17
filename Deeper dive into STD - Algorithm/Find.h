#pragma once
#include <iostream>
#include <vector>

#include "Person.h"

using namespace std;

void findNumbers(vector<int>& numbers)
{
	// Number finding -----------------------------------------------------------------------
	vector<int>::iterator foundNumber;

	int valueToFind = 34;
	std::cout << "Do we find the number = " << valueToFind << "?" << std::endl;
	foundNumber = std::find(numbers.begin(), numbers.end(), valueToFind);
	if (foundNumber != numbers.end())
	{
		cout << *foundNumber << endl;
	}
	else
	{
		cout << valueToFind << " not found" << endl;
	}

	valueToFind = 73;
	foundNumber = std::find(numbers.begin(), numbers.end(), valueToFind);
	if (foundNumber != numbers.end())
	{
		cout << *foundNumber << endl;
	}
	else
	{
		cout << valueToFind << " not found" << endl;
	}

	cout << endl;

}

void findPersons(std::vector<Person>& persons){

	// Person finding
	vector<Person>::iterator personFound = persons.end();

	string nameToFind = "Cesar";

	std::cout << "Do we find the name = " << nameToFind << "?" << std::endl;
	personFound = find_if(
		persons.begin(), 
		persons.end(), 
		[nameToFind](Person p) {return p.getName() == nameToFind; });
	
	// PB : no operator == 
	if(personFound != persons.end())
	{
		personFound->display();
	}
	cout << endl;

}
