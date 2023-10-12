

#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <vector>

int main()
{

    int width = 2;
    int height = 3;

    int datas_typeC[6] = {
    0,1,2,3,4,5
    };
    std::cout << datas_typeC[12] << std::endl;

    std::array<int, 6> datas_typeCPlusPlus;
    datas_typeCPlusPlus.fill(0);

    std::vector<int> datas_vector = {0,1,2,3,4};
    datas_vector.erase(datas_vector.begin(), datas_vector.end());

    for(int i = 0; i < width * height; ++i)
    {
        datas_vector.push_back(i);
    }


    // Parcours par comptage
    for(int i = 0; i < datas_vector.size(); ++i)
    {
        std::cout << datas_vector.at(i) << std::endl;
        std::cout << datas_vector[i] << std::endl;
    }
    // Parcours par affection dans une variable
    for(int element : datas_vector)
    {
        std::cout << element << std::endl;
    }
    // Parcours par iterateur
    for(std::vector<int>::iterator it = datas_vector.begin(); it < datas_vector.end(); ++it)
    {
        std::cout << *it << std::endl;
    }


    // List -----------------------------------------------
    std::list<int> datas_list;

    // Queue -----------------------------------------------
    int size = 10;

    std::queue<int> datas_queue;
    for(int i = 0; i < size; i++)
    {
        datas_queue.push(i);
    }

    while (!datas_queue.empty())
    {
    	std::cout << datas_queue.front() << std::endl;
        datas_queue.pop();
    }

    // Satck -----------------------------------------------
    std::cout << " STACK -------------------------- " << std::endl << std::endl << std::endl;
    std::stack<int> datas_stack;
    for (int i = 0; i < size; i++)
    {
        datas_stack.push(i);
    }

    while (!datas_stack.empty())
    {
        std::cout << datas_stack.top() << std::endl;
        datas_stack.pop();
    }

    // Map
    std::map<char, int> data_map;

    data_map.emplace('a', 10);
    data_map['a'];
    int value = data_map.at(97);

    std::map<std::string, int> notes_formative1;
    notes_formative1.emplace("Anthony", 6);
    notes_formative1.emplace("Linus", 6);

    if (notes_formative1.find("Jayson") != notes_formative1.end())
    {
	    notes_formative1.at("Jayson") = 2;
    	notes_formative1["Jayson"] = 4;
    }
    else
    {
	    notes_formative1["Jayson"] = 6;
    }

    std::cout << "Notes de Jayson" << notes_formative1["Jayson"] << std::endl;
    std::cout << "Notes de Jayson" << notes_formative1["Anthony"] << std::endl;

    for(std::pair<std::string, int> n : notes_formative1)
    {
        std::cout << n.first << ":" << n.second << std::endl;
    }

    // Set
    // Dictionnaries

}
