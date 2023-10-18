#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

void printInt(int e)
{
	std::cout << "print : " << e << std::endl;
}

void printString(std::string e)
{
	std::cout << "print : " << e << std::endl;
}

class Student
{
	std::string Name;
	int Age;

public:
	Student(std::string _n, int _a) : Name(_n), Age(_a) {};

	void Display()
	{
		std::cout << Name << ":" << Age << std::endl;
	}
	int getAge() { return Age; }
};

int main()
{

	int newValue = 2;

	std::vector<int> v = { 12, 6, 32, 1 };

	//std::for_each(v.begin(), v.begin() + 2,
	//	[&](int& e)
	//	{
	//		e = newValue++;
	//	});

	//std::for_each(v.begin(), v.end(),
	//	[](int e)
	//	{
	//		std::cout << "print : " << e << std::endl;
	//	});


	std::vector<int> w = { 1,2,3,4,5 };

	std::copy(v.begin(), v.end(), std::back_inserter(w));
	std::copy(v.begin(), v.end(), std::back_inserter(w));
	std::sort(w.begin(), w.end());

	std::for_each(w.begin(), w.end(),
		[](int e)
		{
			std::cout << "print : " << e << std::endl;
		});

	int c = std::count_if(w.begin(), w.end(), [](int e) {return e % 3 == 0; });


	std::vector<Student> myClass;
	myClass.emplace_back("Jayson", 25);
	myClass.emplace_back("Antoine", 19);

	srand(time(0));

	std::sort(myClass.begin(), myClass.end(), [](Student l, Student r)
	{
			return rand();
	});

	std::for_each(myClass.begin(), myClass.end(),

		[] (Student s)
		{
			s.Display();
		}

		);

	return 0;

}
