#pragma once
#include <string>

enum Section
{
	GameArt,
	GameProg,
	Audio
};

struct Student
{
	std::string Name;
	std::string FirstName;
	int Age;
	Section Section;
};
