#pragma once
#include "Person.h"

void displayNumbers(vector<int> numbersToDisplay)
{
	std::cout << "Display array -- -- -- -- -- -- -- -- -- -- -- -- " << std::endl;

	for (auto it = numbersToDisplay.begin(); it != numbersToDisplay.end(); ++it) {

		std::cout << *it;
		if(it != numbersToDisplay.end() - 1)
			std::cout << ";";

	}

	std::cout << std::endl << std::endl;

}

void displayEverybody(vector<Person>& personsToDisplay)
{
	std::cout << "Are you here, Everybody ?" << std::endl;

	for (auto p : personsToDisplay)
	{
		p.display();
	}

	std::cout << "Yeahhhhhhhhh !!!!!" << std::endl << std::endl;

}

void displayOldPeople(vector<Person>& personsToDisplay, const float ageLimit)
{
	std::cout << "Are you here, grandpa's ?" << std::endl;

	std::for_each(
		personsToDisplay.begin(),			// Start interval
		personsToDisplay.end(),				// End interval
		[&ageLimit](Person& p)		// What to do in each loop turn
		{
			if (p.getAge() >= ageLimit)					// in the lamba expression, why not using if code and custom conditions
				p.display();
		}
	);

	std::cout << "Gnnnnnnenenn !!!!!" << std::endl << std::endl;

}

