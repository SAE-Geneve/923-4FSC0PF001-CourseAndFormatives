// EXERCISE: "chasse au trésor" – given an array of cells representing a 4 by 4 playfield, draw
//           the playfield in the console with characters. 
#include <stdlib.h>
#include <iostream>

#define WIDTH 5
#define HEIGHT 8

int cells[WIDTH * HEIGHT];

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

int input()
{
    int x;
    int y;

	std::cout << "Coordonees de recherche ?" << std::endl;

    std::cout << "X ?" << std::endl;
    std::cin >> x;

    std::cout << "Y ?" << std::endl;
    std::cin >> y;

    int result;
    result = (y - 1) * WIDTH + (x - 1);

    return result;

}

// SOLUTION 2: Calculate the cell index based on row and column
int main()
{

    bool treasureFound = false;

	do
	{
        int idxSearch = input();

        if(cells[idxSearch] == 0)
        {
            std::cout << "no treasure" << std::endl;
        }else
        {
            std::cout << "treasure found !" << std::endl;
        }

		drawPlayfield();

    } while (treasureFound == false);

    return EXIT_SUCCESS;
}

// NEXT STEPS:
//    - make "cells" a global variable (move it outside main, near the top of the file).
//    - extract the code that draws your playfield in a draw_playfield function. Call that function from main.
//    - in main, add an infinite loop. In the loop, drawing the playfield by calling the function, then ask the
//      player for x and y coordinates. Modify the corresponding value in the array. That way the player will be
//      able to select cells to "dig" in search of the treasure.
//    - add a secret cell that is the treasure, if the player digs there, they won! Put a special value in the
//      corresponding array location, and show the playfield (whith a different character representing the
//      treasure). You can hardcode the secret cell at first, then maybe make it random (google is your friend).
//    - instead of representing cells with ints (0, 1, and 2), use an enum CellType.
// 
