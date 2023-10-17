// 07 - Deeper into STD - Classroom - ioFile.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // Read a file
    std::ifstream infile;
    infile.open("read.txt");
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            std::string line;
            std::getline(infile, line);
        	//infile >> line;
            std::cout << line << std::endl;
        }
    }
    infile.close();

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
    for(auto& str : strings)
    {
        outFile << str << std::endl;
    }
    outFile.close();

}

