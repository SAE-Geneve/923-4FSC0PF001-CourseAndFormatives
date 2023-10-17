
#include <iostream>

#include "Fight.h"
#include "Monster.h"
#include "Troll.h"


int main()
{
    std::cout << "Hello World!\n";

    /*Monster genericMonster(50);*/
    // Power = 2D6 + 2
    Troll trollCave("Cave", 2 + 2*Fight::RNG() * 6);
    Troll trollForest("forest", 20);

    //genericMonster.GetHealth(); // Does not work, private !
    trollCave.GetHealth();
    trollForest.SetHealth(25);

    //std::cout << "Generic monster " << genericMonster.ToString() << std::endl;
    std::cout << "Cave Troll " << trollCave.ToString() << std::endl;
    std::cout << "Forest Troll " << trollForest.ToString() << std::endl;


    bool continuePlaying;

    do
    {

        // Choix --------------------------------------------
        Monster monsterA = trollCave;
        Monster monsterB = trollForest;

        bool fightIsOver;
        // Fight ----------------------------------------
        do
        {
            Fight::Combat(monsterA, monsterB);
        } while (fightIsOver);



    } while (continuePlaying);


}
