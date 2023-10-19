#include <iostream>

#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"

int main()
{



	Weapon theRealMagicSword("I am Excalibur, too!", 250);

    Inventory invClass;
    invClass.Add(theRealMagicSword);

    Weapon equipedWeapon = theRealMagicSword;
    int atk = 0;
    int hp = 0;

    char answerExit;
    int answerUse;

    do
    {

        system("cls");

    	// -------------------------------------------------------------------
        // Display all items -------------------------------------------------
        invClass.Display();

        std::cout << "Use any objects [0..9] ?" << std::endl;
        std::cin >> answerUse;

    	// -------------------------------------------------------------------
		Item* monItem = invClass.UseOne(answerUse);
        if(monItem != nullptr)
        {
            monItem->Use();
        }

        std::cout << "Hero -------------------------------" << std::endl;
        std::cout << "Equiped Weapon :" << equipedWeapon.ToString() << std::endl;
        std::cout << "hp :" << hp << std::endl;
        std::cout << "atk :" << atk << std::endl;

        std::cout << "Quit Y/N ?" << std::endl;
        std::cin >> answerExit;
        
    } while (answerExit != 'y');

    //std::cout << "terra\nnova" << std::endl;

    return EXIT_SUCCESS;

}

