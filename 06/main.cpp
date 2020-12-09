#include <iostream>
#include <fstream>
#include <vector>
#include <set>

void print_set(std::set<char> & s)
{
    for(auto it = s.begin(); it != s.end(); it++)
    {
        std::cout<<*it<<" ";
    }

    std::cout<<std::endl;
}

int main()
{
    std::ifstream file("input.txt");
    std::set<char> chars;
    std::string line;
    int result = 0;
    chars.clear();
    while(std::getline(file, line))
    {
        std::cout<<line<<std::endl;
        std::cout<<line.size()<<std::endl;
        if(line.size() == 0)
        {
            result += chars.size();
            print_set(chars);
            std::cout<<chars.size()<<std::endl;
            chars.clear();
        }

        else
            for(int i = 0; i < line.size(); i++)
            {
                chars.insert(line.c_str()[i]);
            }
    }
    result += chars.size();
    chars.clear();
    std::cout<< result<<std::endl;
    return 0;
}
