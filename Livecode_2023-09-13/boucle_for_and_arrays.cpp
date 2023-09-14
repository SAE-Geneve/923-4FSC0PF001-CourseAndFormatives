// EXERCISE / EXAMPLE – array and for loop

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    const char* name = "Sébastien";

    const char* names[9] = {
        "Linus",
        "Maxence",
        "Maxime",
        "Adelina",
        "Jayson",
        "Matthieu",
        "Anthony",
        "Antoine",
        "Thomas",
    };

    // Access and print an array element
    std::cout << names[6] << "\n";

    // NOTE: two ways to increment variable a by 1:
    // a = a + 1;
    // a++;

    // Print all elements, and the index + 1
    for (int a = 0; a < 9; a++)
    {
        std::cout << (a + 1) << ": " << names[a] << std::endl;
    }

    return EXIT_SUCCESS;
}
