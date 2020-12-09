#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

void print_set(std::set<char> & s)
{
    for(auto it = s.begin(); it != s.end(); it++)
    {
        std::cout<<*it<<" ";
    }

    std::cout<<std::endl;
}
void print_vector(std::vector<char> & s)
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
    std::vector<char> intersection;
    std::string line;
    int result = 0;
    intersection.clear();
    bool in_group = false;
    while(std::getline(file, line))
    {
        if(line.size() == 0)
        {
            result += intersection.size();
            in_group = false;
            intersection.clear();
        }

        else
        {
            std::vector<char> newchars;
            for(int i = 0; i < line.size(); i++)
            {
                newchars.push_back(line[i]);
            }
            if(in_group)
            {
                std::vector<char> temp;
                std::sort(intersection.begin(), intersection.end());
                std::sort(newchars.begin(), newchars.end());
                std::set_intersection(intersection.begin(), intersection.end(), newchars.begin(), newchars.end(), std::back_inserter(temp));
                intersection = temp;
            }
            else
            {
                intersection = newchars;
                in_group = true;
            }
        }
    }
    result += intersection.size();
    std::cout<< result<<std::endl;
    return 0;
}
