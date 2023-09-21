#pragma once

enum Status
{
	None,
	Poisoned,
	Burned,
	Tired,
	Stunned,
	Acidified,

	nbStatusAvailable
};

void DisplayStatus(Status playerStatus)
{
	switch (playerStatus)
	{
	case Status::Poisoned:
		std::cout << "empoisonne" << std::endl;

	case Status::Burned:
		std::cout << "brule" << std::endl;
		break;

	case Status::Tired:
		std::cout << "fatigue" << std::endl;
		break;

	case Status::Stunned:
		std::cout << "assome" << std::endl;
		break;

	case Status::None:
	default:
		std::cout << std::endl;
		break;
	}



}
