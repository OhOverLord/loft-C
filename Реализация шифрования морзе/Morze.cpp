#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void read_file(std::vector<std::string>& morze, std::string file_name)
{
    std::ifstream in(file_name);
    std::string str;
    while (in >> str)
        morze.push_back(str);
    in.close();
}

int main()
{
    std::vector<std::string> mass_morze;
    std::vector<std::string> mass_alphabet;
    read_file(mass_morze, "morze.txt");
    read_file(mass_alphabet, "alphabet.txt");
    std::string user_input;
    std::getline(std::cin, user_input);
    int j;
    for (int i = 0; i < user_input.size(); i++)
        if (user_input[i] != ' ')
        {
            for (j = 0; j < mass_alphabet.size(); j++)
                if (user_input[i] == mass_alphabet[j][0])
                    break;
            std::cout << mass_morze[j] << " ";
            j = 0;
        }
        else
            std::cout << " ";
}
