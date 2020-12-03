#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    int x = 0;
    int y = 0;

    int dx = 3;
    int trees = 0;

    std::ifstream file("input.txt");
    std::string line;
    std::getline(file, line);
    int w = line.size();
    while(std::getline(file, line))
    {

        //movement
        y ++;
        x += dx;
        x = x%w;
        if(line.c_str()[x] == '#')
            trees++;
    }
    std::cout<<trees<<std::endl;
    return 0;
}
