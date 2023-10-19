#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {

	int barreDeVie = 100;
	json j;

	// Charger les données ----------------------------------------------------------
	std::ifstream i("datas.json");
	j = json::parse(i);

	barreDeVie = j["barreDeVie"];
	i.close();

	// Actions de l'inventaire ------------------------------------------------------
	barreDeVie--;
	std::cout << "Barre de vie = " << barreDeVie << std::endl;

	// Sauvegarde les données -------------------------------------------------------
	j["barreDeVie"] = barreDeVie;

	std::ofstream o("datas.json");
	o << std::setw(4) << j << std::endl;
	o.close();

	return EXIT_SUCCESS;

}