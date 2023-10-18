// 07 - Deeper into STD - Classroom - ioFile.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	// Read a file
	std::ifstream infile;
	infile.open("test.xml");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			std::string line;
			std::getline(infile, line);
			//infile >> line;
			std::cout << line << std::endl;
		}
	}
	infile.close();

	// Read a file
	std::string name;
	int hp = 0, atk = 0, def = 0;
	int idxLine = 0;

	std::ifstream perso;
	perso.open("perso.txt");
	if (perso.is_open())
	{
		while (!perso.eof())
		{
			std::string line;
			std::getline(perso, line);

			switch (idxLine++)
			{
			case 0:
				name = line;
				break;
			case 1:
				hp = std::stoi(line);
				break;
			case 2:
				atk = std::stoi(line);
				break;
			case 3:
				def = std::stoi(line);
				if (def <= 0)
					def = 1;
				break;
			}

			//infile >> line;
			std::cout << line << std::endl;
		}
	}
	perso.close();

	// Write in a file : ofstream
// it will create the file if not exists
	std::ofstream perso_out("perso.txt");

	perso_out << name << std::endl;
	perso_out << hp << std::endl;
	perso_out << atk << std::endl;
	perso_out << def << std::endl;

	//perso_out.write("$$virus$$", 2);

	perso_out.close();


	// Write in a file : ofstream
	// it will create the file if not exists
	std::ofstream outFile("write.txt");
	// Some text
	std::vector<std::string> strings = {
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
		"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.",
		"Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.",
		"Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
	};

	// Each line goes into the file
	for (auto& str : strings)
	{
		outFile << str << std::endl;
	}
	outFile.close();



	std::ostringstream out_string{};
	out_string << "hello ";
	std::string _name;
	std::cin >> _name;
	out_string << _name;
	out_string << "!\n";
	std::cout << out_string.str();

}

