#include "Fight.h"

#include <random>

#include "Troll.h"


void Fight::Combat(Monster& attacker, Monster& defender)
{
}

float Fight::RNG()
{
    std::random_device rd;

    //
    // Engines 
    //
    std::mt19937 e2(rd());
    //std::knuth_b e2(rd());
    //std::default_random_engine e2(rd()) ;

    //
    // Distribtuions
    //
    std::uniform_real_distribution<> distReal(0, 1);

    return distReal(e2);

}
