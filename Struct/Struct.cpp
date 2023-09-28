
#include <iostream>
#include <vector>

#include "Student.h"

int main()
{

    Student jayson;
    jayson.FirstName = "Jayson";
    jayson.Name = "Malet";
    jayson.Age = 25;
    jayson.Section = Section::GameProg;

    Student anthony{
    "Barman", "Anthony", 20, Section::GameProg
    };

    Student genericStudent;
    genericStudent = jayson;

    std::vector<Student> myClass;
    myClass.push_back(jayson);
    myClass.push_back({ "Albert", "Sebastien", 45, Section::GameProg });
    myClass.push_back({"Barman", "Anthony", 20, Section::GameProg});

   if(jayson.Age > anthony.Age)
   {
       std::cout << "Jayson est plus agé que Anthony" << std::endl;
   }

    std::cout << genericStudent.Name << " " << genericStudent.FirstName;

}

