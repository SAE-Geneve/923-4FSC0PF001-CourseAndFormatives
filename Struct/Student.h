#pragma once
#include <string>

enum class Section
{
	GameArt,
	GameProg,
	Audio
};

struct Student
{
	std::string FirstName;
	std::string Name;
	int Age;
	Section StudentSection;
};
