// Inheritance.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Monster.h"
#include "Troll.h"

int main()
{
    std::cout << "Hello World!\n";

    /*Monster genericMonster(50);*/

    Troll trollCave("Cave", 15);
    Troll trollForest("forest", 20);

    //genericMonster.GetHealth(); // Does not work, private !
    trollCave.GetHealth();
    trollForest.SetHealth(25);

    //std::cout << "Generic monster " << genericMonster.ToString() << std::endl;
    std::cout << "Cave Troll " << trollCave.ToString() << std::endl;
    std::cout << "Forest Troll " << trollForest.ToString() << std::endl;

    Monster monster = trollCave;


}
