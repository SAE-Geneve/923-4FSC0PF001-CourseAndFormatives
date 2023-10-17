#include "Person.h"

#include <iostream>

using namespace std;

std::vector<Person> Person::initPersons()
{
	std::vector<Person> persons;

	persons.emplace_back(Person("De Gaulle", "Charles", 72));
	persons.emplace_back(Person("Premier", "Napoleon", 56));
	persons.emplace_back(Person("Le Hun", "Attila", 37));
	persons.emplace_back(Person("Cesar", "Jules", 48));
	persons.emplace_back(Person("Getorix", "Vercin", 27));
	persons.emplace_back(Person("Christ", "Jesus", 33));

	return persons;

}

Person::Person(const string name, const string firstName, const float age)
{
	name_ = { name };
	firstName_ = (firstName);
	age_ = { age };
}

string Person::getName()
{
	return name_;
}

string Person::getFirstName()
{
	return firstName_;
}

float Person::getAge()
{
	return age_;
}

void Person::display()
{
	cout << "My name is " << firstName_ << " " << name_ << ".I'm " << age_ << " years old." << endl;
}

bool Person::operator==(Person& p)
{
	return (
		p.age_ == this->age_ &&
		p.name_ == this->name_ &&
		p.firstName_ == this->firstName_
		);
}

