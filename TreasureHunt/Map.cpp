
#include <iostream>
#include <string>

#include "Map.h"

int Cells[WIDTH * HEIGHT];

void InitializeMap()
{

    for(auto& c : Cells)
    {
        c = Empty;
    }

    int idxRandom = RandomCustom(0, WIDTH * HEIGHT);
    Cells[idxRandom] = Coffre;

}

void DrawPlayfield(bool _debugMode)
{
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {

            int index = row * WIDTH + column;
            int cell = Cells[index];

            if (cell == TreasureTiles::Empty) {
                std::cout << '-';
            }
            else {
            	std::cout << 'x';
            }
        }
        std::cout << '\n';
    }
}

int ValidInput()
{

    bool isValidInput = true;
    int result = -1;

    std::string inputString;
    do
    {
        std::getline(std::cin, inputString);

        isValidInput = true;
        for (char inputChar : inputString)
        {
            if (!isdigit(inputChar))
            {
                // not valid input -----------------
                std::cout << "[" << inputChar << "] is not a number" << std::endl;
                isValidInput = false;
                break;
            }
        }

        if (isValidInput)
        {
            //std::cout << "Your number is: " << inputString << "\n";
            std::string value = inputString.substr(0, 10);

            result = std::stoi(inputString);

            std::cout << "Your number is: " << result << "\n";
            break;
        }

    } while (!isValidInput);

    return result;

}

int Input()
{

    int x;
	int y;

    std::cout << "Coordonees de recherche ?" << std::endl;

    std::cout << "X ?" << std::endl;
    x = ValidInput();

    std::cout << "Y ?" << std::endl;
    y = ValidInput();

    int result;
    result = (y - 1) * WIDTH + (x - 1);

    return result;

}

