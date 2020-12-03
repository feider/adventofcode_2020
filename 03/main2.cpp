#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    int x = 0;
    int y = 0;

    int dx, dy;
    long int trees_mult = 1;

    std::vector<int> vx = {1, 3, 5, 7, 1};
    std::vector<int> vy = {1, 1, 1, 1, 2};

    for(int v = 0; v<vx.size(); v++)
    {
        int trees = 0;
        x = 0;
        y = 0;
        dx = vx[v];
        dy = vy[v];

        std::ifstream file("input.txt");
        std::string line;
        std::getline(file, line);
        int w = line.size();
        bool end = false;
        while(!end)
        {
            for(int _y = 0; _y<dy && !end; _y++)
            {
                end = !std::getline(file, line);
            }
            y += dy;
            x+=dx;
            x = x%w;
            if(!end)
            {

                //movement
                if(line.c_str()[x] == '#')
                    trees++;
            }
        }
        std::cout<<trees<<std::endl;
        trees_mult *= trees;
    }
    std::cout<<trees_mult<<std::endl;
    return 0;
}
