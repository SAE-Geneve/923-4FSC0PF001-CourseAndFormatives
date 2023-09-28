#include <iostream>
#include <string>

int main()
{
    std::string sentence_in;

    std::cout << "Please input a string" << std::endl;
    std::getline(std::cin, sentence_in);

    std::string sentence_out = sentence_in;

    sentence_out[0] = toupper(sentence_out[0]);

    for (int i = 0; i < sentence_out.length() - 1; i++)
    {
        if (sentence_out[i] == ' ')
        {
            std::cout << " espace " << std::endl;
        	//sentence_out[i + 1] = toupper(sentence_out[i + 1]);
        }else
        {
            std::cout << " pas espace " << std::endl;
        }
    }

    std::cout << "Sample input: " << sentence_in << std::endl;
    std::cout << "Sample output: " << sentence_out << std::endl;

}