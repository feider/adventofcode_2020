#include <iostream>
#include <vector>
#include <fstream>


void unpack_code(std::string & code, int & row, int & col, int & id)
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

    int id_max = 0;

    int row, col, id;

    std::ifstream file("input.txt");
    std::string line;
    while(std::getline(file, line))
    {
        unpack_code(line, row, col, id);
        if(id>id_max)
            id_max = id;
    }
        
    std::cout<<id_max<<std::endl;
}
