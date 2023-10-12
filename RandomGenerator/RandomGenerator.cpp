// RandomGenerator.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <random>

int main()
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
    std::uniform_int_distribution<> distInt(0, 100);
    std::uniform_real_distribution<> distReal(0, 100);
    //std::normal_distribution<> dist(2, 2);
    //std::student_t_distribution<> dist(5);
    std::poisson_distribution<> distPoisson(50);
    //std::extreme_value_distribution<> dist(0,2);

    for(int nbTirage = 0; nbTirage <= 100; nbTirage++)
    {

        std::cout << "Nouveau tirage --------------------------------------- " << std::endl;
    	std::cout << "Tirage entier : " << distInt(e2) << std::endl;
        std::cout << "Tirage réel : " << distReal(e2) << std::endl;
        std::cout << "Tirage poisson : " << distPoisson(e2) << std::endl;
    }



    //std::map<int, int> hist;
    //for (int n = 0; n < 10000; ++n) {
    //    ++hist[std::floor(dist(e2))];
    //}

    //for (auto p : hist) {
    //    std::cout << std::fixed << std::setprecision(1) << std::setw(2)
    //        << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    //}
}
