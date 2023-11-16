// Const.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Entity
{
public:
    int m_ = 0;
};

class ConstEntity
{
public:
    std::string name;
    const int m_ = 0;

    ConstEntity& operator= (const ConstEntity& ee)
    {
        this->name = ee.name;
    	return *this;
    }
};

int main()
{
    // Ints -------------------------------
	int a = 6;
    const int b = 3;

    a = 2;
    //b = 5; // Can not assign, b is const

    a = b;
    //b = a; // Can not copy, b is const


    // Classes -------------------------------------
    Entity e;
    const Entity f;
    e.m_ = 12;
    e = f;
    //f = e; // Can not copy to the const entity

    ConstEntity g, h;
    //g.m_ = 12; // m_ is a const member
    h.name = "h"; g.name = "g";
    g = h; // Should not work (deleted function issue), thanks to copy operator

    std::cout << "G = " << g.name << " H = " << h.name << " Should have switch...." << std::endl;


    // What if we use vector ????????????????????????????????????????????????????????
    std::vector<Entity> entity_vector;
    for(int i = 0; i < 10; i++)
    {
        Entity add_entity;
        add_entity.m_ = i;
        entity_vector.emplace_back(add_entity);
    }
    std::_Erase_remove_if(entity_vector, [](Entity& e) {return e.m_ == 2; });
    std::_Erase_remove_if(entity_vector, [](Entity& e) {return e.m_ == 7; });
    std::_Erase_remove_if(entity_vector, [](Entity& e) {return e.m_ == 12; });


    std::vector<ConstEntity> const_entity_vector;
    for (int i = 0; i < 10; i++)
    {
        ConstEntity add_entity;
        add_entity.name = std::to_string(i);
        const_entity_vector.emplace_back(add_entity);
    }
    std::_Erase_remove_if(const_entity_vector, [](ConstEntity& e) {return e.name == "2"; });
    std::_Erase_remove_if(const_entity_vector, [](ConstEntity& e) {return e.name == "7"; });
    std::_Erase_remove_if(const_entity_vector, [](ConstEntity& e) {return e.name == "12"; });

}
