#include <iostream>

#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"

int main()
{
    Item magicSword("Excalibur !");
    Weapon theRealMagicSword("I am Excalibur, too!", 250);

    Inventory invClass;

    for(int i = 0; i < 10 ; i++)
    {
        Item itemToAdd(std::to_string(i));

        invClass.Add(itemToAdd);

    }

    invClass.Display();

    // -------------------------------------------------------------------

    Item monItem = invClass.Equip(0);
    monItem.Use();

    std::cout << "terra\nnova" << std::endl;

    return EXIT_SUCCESS;

}

