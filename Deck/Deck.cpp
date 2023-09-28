

#include <iostream>

enum Rank
{
	Two,
};

struct Card
{
    Rank Rank;
};

int main()
{
    std::cout << "Hello World!\n";

    int valeur_cardA = 3;
    std::string couleur_cardA = "pique";
    
    std::cout << valeur_cardA << " de " << couleur_cardA << std::endl;


}
