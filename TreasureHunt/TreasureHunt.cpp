// EXERCISE: "chasse au trésor" – given an array of cells representing a 4 by 4 playfield, draw
//           the playfield in the console with characters. 
#include <stdlib.h>
#include <iostream>

#include "Map.h"

#include "Random.h"

#define DEBUG_INDEX 158

// SOLUTION 2: Calculate the cell index based on row and column
int main()
{
	bool treasureFound = false;
	int nbAttempts = 0;

	InitializeMap();

	do
	{
		system("cls");

		int idxSearch = Input();

		if (Cells[idxSearch] == TreasureTiles::Empty)
		{
			std::cout << "no treasure" << std::endl;
			treasureFound = false;
		}
		else
		{
			std::cout << "treasure found !" << std::endl;
			treasureFound = true;
		}

		DrawPlayfield(false);

		nbAttempts++;

	} while (treasureFound == false && nbAttempts < 3);

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
