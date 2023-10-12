// AutoPoker.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Player.h"

void Bet(int bet, Player& player)
{
    player.pot -= bet;
}

int main()
{
    Player player1;
    player1.pot = 1000;

    Player player2;
    player2.pot = 1000;

    Bet(50, player1);
    Bet(100, player2);

    std::cout << player1.pot << std::endl;
    std::cout << player2.pot << std::endl;

    return EXIT_SUCCESS;

}

