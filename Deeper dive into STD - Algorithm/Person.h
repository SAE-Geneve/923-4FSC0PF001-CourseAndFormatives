#pragma once
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
	string name_;
	string firstName_;
	float age_;

public:
	static vector<Person> initPersons();

	Person(string name, string firstName, float age);

	string getName();
	string getFirstName();
	float getAge();
	void display();

	bool operator==(Person &);
	bool operator<(Person&);

};

