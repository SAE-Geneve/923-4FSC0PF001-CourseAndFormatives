#include <cstdlib>
#include <ctime>
#include <iostream>

int RandomCustom(int min, int max)
{
    srand(time(0));

    return min + rand() % (max);

}
