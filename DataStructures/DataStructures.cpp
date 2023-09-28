

#include <array>
#include <iostream>
#include <list>
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
    //datas_vector[8] = 63;
    //datas_vector.at(7) = 64;
    //datas_vector.insert(datas_vector.begin() + 8, 65);

    for(int i = 0; i < datas_vector.size(); ++i)
    {
        std::cout << datas_vector.at(i) << std::endl;
    }

    for(int element : datas_vector)
    {
        std::cout << element << std::endl;
    }

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
    std::cout << "STACK --------------------------" << std::endl << std::endl << std::endl;
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

}
