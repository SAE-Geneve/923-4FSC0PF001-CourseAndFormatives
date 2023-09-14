// EXERCISE: "chasse au trésor" – given an array of cells representing a 4 by 4 playfield, draw
//           the playfield in the console with characters. 
#include <stdlib.h>
#include <iostream>
/*
int main()
{
    int cells[4 * 4] = {
        0, 0, 0, 0,
        0, 0, 0, 1,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            int cell_val = cells[? ? ? ? ]; // <------ how to access the correct cell?

            if (cell_val == 0) {
                std::cout << '-';
            }
            else {
                std::cout << 'x';
            }
        }
        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}*/

// SOLUTION 1: Increment an index variable each time we draw a cell.
int main()
{
    int cells[4 * 4] = {
        0, 0, 0, 0,
        0, 0, 0, 1,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };

    int cell_index = 0;
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            int cell = cells[cell_index];
            cell_index++;

            if (cell == 0) {
                std::cout << '-';
            }
            else {
                std::cout << 'x';
            }
        }
        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}



// SOLUTION 2: Calculate the cell index based on row and column

/*
int main()
{
    int cells[4 * 4] = {
        0, 0, 0, 0,
        0, 0, 0, 1,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };

    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            int cell = cells[row * 4 + column];

            if (cell == 0) {
                std::cout << '-';
            }
            else {
                std::cout << 'x';
            }
        }
        std::cout << '\n';
    }

    return EXIT_SUCCESS;
}
*/

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
