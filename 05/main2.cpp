#include <iostream>
#include <vector>
#include <fstream>



void unpack_code(const std::string & code, int & row, int & col, int & id)
{
    const char * str = code.c_str();
    int rows = 128;
    int cols = 8;
    row = 0;
    col = 0;

    for(int i = 0; i<7; i++)
    {
        rows /= 2;
        char c = str[i];
        if(c == 'B')
            row += rows;
    }
    for(int i = 7; i<10; i++)
    {
        cols /= 2;
        char c = str[i];
        if(c == 'R')
            col += cols;
    }
    id = row*8+col;

}

int main()
{


    int row, col, id;

    unpack_code("BBBBBBBRRR", row, col, id);


    std::vector<bool> ids(id+1);
    std::fill(ids.begin(), ids.end(), false);

    int id_max = 0;
    int id_min = id;



    std::ifstream file("input.txt");
    std::string line;
    while(std::getline(file, line))
    {
        unpack_code(line, row, col, id);
        if(id>id_max)
            id_max = id;
        if(id<id_min)
            id_min = id;
        ids[id] = true;
    }

    for(int i = id_min+1; i < id_max; i++)
    {
        if(ids[i-1] && ids[i+1] && !ids[i])
            std::cout<<i<<std::endl;
    }
    return 0;
}
