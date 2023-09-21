
#include <iostream>
#include <string>

#include "Map.h"


void initializeMap()
{

    for(auto& c : cells)
    {
        c = plateau;
    }

    int idxRandom = RandomCustom(0, WIDTH * HEIGHT);

    cells[idxRandom] = coffre;

}

void drawPlayfield()
{
    for (int row = 0; row < HEIGHT; row++) {
        for (int column = 0; column < WIDTH; column++) {

            int index = row * WIDTH + column;
            int cell = cells[index];

            if (cell == 0) {
                std::cout << '-';
            }
            else {
                std::cout << 'x';
            }
        }
        std::cout << '\n';
    }
}

int validInput()
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
            result = std::stoi(inputString);
            std::cout << "Your number is: " << result << "\n";
            break;
        }

    } while (!isValidInput);

    return result;

}

int input()
{
    int x;
    int y;

    std::cout << "Coordonees de recherche ?" << std::endl;

    std::cout << "X ?" << std::endl;
    x = validInput();

    std::cout << "Y ?" << std::endl;
    y = validInput();

    int result;
    result = (y - 1) * WIDTH + (x - 1);

    return result;

}

