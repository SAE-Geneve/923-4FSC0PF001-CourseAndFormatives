#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

#include "item.h"

using json = nlohmann::json;

void Load(std::string fileName, std::vector<item*>& datas)
{
	json inJson;

	// Charger les données ----------------------------------------------------------
	std::ifstream inStream(fileName);
	inJson = json::parse(inStream);

	if(inJson.contains("tableau"))
	{
		for(auto& element : inJson["tableau"])
		{

			item* i = new item;

			i->force = element["force"];
			i->name = element["name"];

			int type = -1;
			if(element.contains("type"))
			{
				i->type = element["type"];
			}


			datas.emplace_back(i);

			//std::cout << "vector element : " << datas.back().name << ":" << datas.back().force << std::endl;
			//std::cout << "-------------------------------------------------------------------" << std::endl;

		}
	}
	inStream.close();
}

void Save(std::string fileName, std::vector<item*>& datas)
{
	json out;

	// Sauvegarde des données -------------------------------------------------------

	for(auto& element : datas)
	{
		json jsonElement;
		jsonElement["force"] = element->force;
		jsonElement["name"] = element->name;
		jsonElement["type"] = element->type;

		out["tableau"].push_back(jsonElement);
	}

	std::ofstream o(fileName);
	o << std::setw(4) << out << std::endl;
	o.close();
}

int main() {

	std::vector<item*> items;

	json inJson, out;

	Load("datas.json", items);

	for(auto& item : items)
	{
		std::cout << "vector element : " << item->name << ":" << item->force << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;

	}

	Save("datas.json", items);


	

	return EXIT_SUCCESS;

}
