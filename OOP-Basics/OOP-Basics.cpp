// OOP-Basics.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Ennemy.h"

int main()
{
    //Ennemy Alien {"Xenomorphe", 25, 35};
    //Ennemy Dragon {"Smaug",45, 60};
    Ennemy Alien("Xenomorphe", 150, 25, 35);
    Ennemy Dragon("Smaug", 150, 45, 60);

    Ennemy mob("mob");

    Dragon.TakeDamage(Alien.attackValue);
    Alien.TakeDamage(Dragon.attackValue);

    Dragon.Heal();
    Alien.Heal(15);

}

