// EXAMPLE enum

//
// Classic way, with #defines (don't use!!)
//
#include <stdio.h>
#include <stdlib.h>

#define BANANE 0
#define POMME 1
#define CERISE 2
    
int main()
{
    int selected_fruit = CERISE;

    switch(selected_fruit)
    {
        case POMME:
            puts("Pomme");
            break;

        case CERISE:
            puts("Cerise");
            break;

        case BANANE:
            puts("Banane");
            break;
    }

    return EXIT_SUCCESS;
}

//
// Classic enum (no "prefix" namespace, name clashes possible with other enums, variables, functions...)
//
#include <stdio.h>
#include <stdlib.h>

enum Fruit {
    BANANE,
    POMME,
    CERISE,
};

int main()
{
    Fruit selected_fruit = CERISE;

    switch(selected_fruit)
    {
        case POMME:
            puts("Pomme");
            break;

        case CERISE:
            puts("Cerise");
            break;

        case BANANE:
            puts("Banane");
            break;
    }

    return EXIT_SUCCESS;
}

//
// C++ 11 class enums (use that!)
//
#include <stdio.h>
#include <stdlib.h>

enum class Fruit {
    BANANE,
    POMME,
    CERISE,
};

int main()
{
    Fruit selected_fruit = Fruit::CERISE;

    switch(selected_fruit)
    {
        case Fruit::POMME:
            puts("Pomme");
            break;

        case Fruit::CERISE:
            puts("Cerise");
            break;

        case Fruit::BANANE:
            puts("Banane");
            break;
    }

    return EXIT_SUCCESS;
}
