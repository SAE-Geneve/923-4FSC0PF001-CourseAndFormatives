// 07 - Deeper dive into STD - Classroom - Algorithm.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

// Algorithms
#include "Copy.h"
#include "Display.h"
#include "Find.h"
#include "Sort.h"

// Classes
#include "Person.h"
#include "Remove.h"


int main()
{
	vector<Person> persons = Person::initPersons();
	vector<int> numbers = { 12, 15, 46, 34, 23, 76, 89, 42 };

	// Copy some
	// numbers
	copyNumbers(numbers);
	// persons
	copyPersons(persons);

	displayOldPeople(persons, 60);

	// Find some
	// Numbers
	findNumbers(numbers);
	// Persons
	findPersons(persons);

	// Sort and shuffle numbers
	displayNumbers(numbers);
	ascendingSortNumbers(numbers);

	descendingSortNumbers(numbers);
	randomShuffleNumbers(numbers);

	// Sort persons
	sortPersons_Lambda(persons);
	shufflePersons(persons);

	sortPersons_Operator(persons);
	shufflePersons(persons);

	sortPersons_Functor(persons);
	shufflePersons(persons);

	// Remove Numbers
	std::cout << "Before remove" << std::endl;
	displayNumbers(numbers);

	removeNumbers(numbers, 42);
	removeNumbers(numbers, 5);

	removeEvenNumbers(numbers);

	// Remove Persons
	std::cout << "Before remove" << std::endl;
	displayEverybody(persons);

	removeIfNamePersons(persons, "Einstein");
	removeIfNamePersons(persons, "Gandhi");
	removeOldPersons(persons, 70);
	
}
