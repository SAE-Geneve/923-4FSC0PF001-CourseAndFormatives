// OperatorOverload.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Sayen.h"

int main()
{
    

    Sayen sangoku;
    Sayen vegeta;

    sangoku.name = "Sangoku";
    sangoku.power = 8999;

    vegeta.name = "Vegeta";
    vegeta.power = 9001;

    Sayen gogeta = sangoku + vegeta;
    Sayen vegeto = vegeta + sangoku;


    if(gogeta == sangoku)
    {
	    
    }

}

